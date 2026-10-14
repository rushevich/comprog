#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <type_traits>

using Timestamp = std::uint64_t; // nanoseconds, monotonic
using Duration = std::uint64_t;  // nanoseconds
using OrderId = std::uint64_t;

enum class MsgType : std::uint8_t { New, Cancel, Modify };

struct Message {
    MsgType type;
    OrderId order_id;
    std::uint32_t strategy_id;
    // ... payload
};

void send(const Message& msg);           // encodes and writes to the socket
void notify_dropped(const Message& msg); // tells the strategy we dropped it

// Fixed-capacity FIFO. One slot is always left empty so that full and empty
// are distinguishable, so we allocate capacity + 1 slots. Allocates only in
// the constructor. Move-only because of the unique_ptr.
template<typename T> class RingBuffer {
  public:
    explicit RingBuffer(std::size_t capacity) : slots_(capacity + 1), buffer_(std::make_unique<T[]>(slots_)) {}

    bool empty() const noexcept { return read_ == write_; }
    bool full() const noexcept { return advance(write_) == read_; }

    bool push(const T& value) noexcept(std::is_nothrow_copy_assignable_v<T>) {
        if (full()) return false;
        buffer_[write_] = value;
        write_ = advance(write_);
        return true;
    }

    T& front() noexcept {
        assert(!empty());
        return buffer_[read_];
    }

    void pop() noexcept {
        assert(!empty());
        read_ = advance(read_);
    }

  private:
    std::size_t advance(std::size_t i) const noexcept { return ++i == slots_ ? 0 : i; }

    std::size_t slots_;
    std::unique_ptr<T[]> buffer_;
    std::size_t read_ = 0;
    std::size_t write_ = 0;
};

// Sits between the strategies and send(). Guarantees no more than `limit`
// messages are sent in any rolling `window`. Cancels always go first; new
// orders and modifies that wait longer than `stale_after` are dropped.
//
// Gateway loop, once per iteration:
//   now = clock();
//   for each msg from the strategy queue: throttle.push(msg, now);
//   throttle.flush(now);
class Throttle {
  public:
    Throttle(std::size_t limit, Duration window, Duration stale_after, std::size_t cancel_capacity,
             std::size_t order_capacity)
        : window_(limit), cancels_(cancel_capacity), orders_(order_capacity), window_len_(window),
          stale_after_(stale_after) {
        assert(limit > 0);
    }

    // Queues a message. Returns false if it could not be queued.
    bool push(const Message& msg, Timestamp now) {
        if (msg.type == MsgType::Cancel) {
            if (cancels_.push(msg)) return true;
            // A full cancel queue means something upstream is badly wrong.
            // We will not break the exchange limit to send it, so tell the
            // strategy and let the caller escalate (e.g. halt the strategy).
            notify_dropped(msg);
            return false;
        }
        if (orders_.push(Pending{msg, now})) return true;
        notify_dropped(msg);
        return false;
    }

    // Sends as much as the window allows, cancels first.
    void flush(Timestamp now) {
        expire(now);

        while (!window_.full() && !cancels_.empty()) {
            send_now(cancels_.front(), now);
            cancels_.pop();
        }

        while (!window_.full() && !orders_.empty()) {
            const Pending& p = orders_.front();
            if (now - p.arrived > stale_after_) {
                notify_dropped(p.msg); // dropping uses no capacity
            } else {
                send_now(p.msg, now);
            }
            orders_.pop();
        }
    }

  private:
    struct Pending {
        Message msg;
        Timestamp arrived;
    };

    // A send exactly one window ago still counts (conservative boundary).
    // Safe subtraction: the clock is monotonic, so now >= every stored time.
    void expire(Timestamp now) noexcept {
        while (!window_.empty() && now - window_.front() > window_len_) { window_.pop(); }
    }

    void send_now(const Message& msg, Timestamp now) {
        send(msg);
        window_.push(now); // record the SEND time, not the arrival time
    }

    RingBuffer<Timestamp> window_; // send times of messages in the window
    RingBuffer<Message> cancels_;
    RingBuffer<Pending> orders_; // new orders and modifies
    Duration window_len_;
    Duration stale_after_;
};
