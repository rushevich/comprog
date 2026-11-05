#include <bits/stdc++.h>

enum class Direction : uint8_t { bid, ask };

struct Fill {
    Direction d;
    double price;
};

struct Reveal {
    double price;
};

struct Settle {
    double price;
};

using Update = std::variant<Fill, Reveal, Settle>;

struct Quote {
    std::optional<double> bid;
    std::optional<double> ask;
};

std::ostream& operator<<(std::ostream& out, const Quote& quote) {
    const auto& [bid, ask] = quote;
    if (!bid) {
        out << "- ";
    } else {
        out << *bid << ' ';
    }
    if (!ask) {
        out << '-';
    } else {
        out << *ask;
    }
    return out;
}

template<typename... Fs> struct overloaded : Fs... {
    using Fs::operator()...;
};

template<typename... Fs> overloaded(Fs...) -> overloaded<Fs...>;

class DiceBot {
  public:
    DiceBot(int maxPosition, int sideCount, int numDice)
        : maxPosition_(maxPosition), hiddenCount_(numDice), sideCount_(sideCount) {}

    // Updates the internal state upon the arrival of an event
    // Fill: updates the position, and current cash amount. bid -> someone sold to you, ask -> you bought from someone
    void update(const Update& update) {
        std::visit(overloaded{[this](const Fill& fill) {
                                  const bool weBought = fill.d == Direction::bid;
                                  position_ += weBought ? 1 : -1;
                                  cash_ += weBought ? -fill.price : fill.price;
                                  flow_ = flow_ * flowDecay_ + (weBought ? -1.0 : 1.0);
                                  // -1 if we bought, the aggressor is selling and this means they MIGHT know something
                                  // we don’t know about V (true value)
                              },
                              [this](const Reveal& reveal) {
                                  if (hiddenCount_ > 0) {
                                      revealedSum_ += reveal.price;
                                      --hiddenCount_;
                                  }
                                  flow_ *= 0.5;
                              },
                              [this](const Settle& settle) {
                                  revealedSum_ = settle.price;
                                  hiddenCount_ = 0;
                              }},
                   update);
    }

    Quote quote() const {
        const auto sd = computeSD();
        double center = computeFV();
        center += std::clamp(flowShift_ * flow_, -sd, +sd);
        // Lean against our position to pull back towards flat
        center -= skew_ * static_cast<double>(position_);

        // Widen the halfwidth if flow is one-sided, since we are less sure of the fair value, and we should charge more
        // to make a market
        const auto halfWidth = std::max((sd / 2.0) * (1.0 + flowWiden_ * std::abs(flow_)), 0.5);
        auto bid = center - halfWidth;
        auto ask = center + halfWidth;

        bid = std::min(bid, revealedSum_ + hiddenCount_ * sideCount_);
        ask = std::max(ask, revealedSum_ + hiddenCount_);

        const double eps = 1e-9;
        bid = std::floor(bid * 10.0 + eps) / 10.0;
        ask = std::ceil(ask * 10.0 - eps) / 10.0;
        Quote quote{bid, ask};
        if (position_ >= maxPosition_) quote.bid.reset();
        else if (position_ <= -maxPosition_) quote.ask.reset();
        return quote;
    }

    double profit() const { return cash_ + position_ * revealedSum_; }

  private:
    int position_{};
    int maxPosition_{};
    int hiddenCount_{};
    double cash_{};
    int sideCount_{};
    double revealedSum_{};

    // Parameters
    double skew_{0.5};
    double flowShift_{0.4};  // how much fair value moves per unit of flow
    double flowWiden_{0.25}; // how much spread widens per unit of flow
    double flowDecay_{0.7};  // how much we trust the old flow on a new fill

    double flow_{};

    double computeFV() const {
        return revealedSum_ + static_cast<double>(hiddenCount_) * ((static_cast<double>(sideCount_) + 1) / 2.0);
    }

    double computeSD() const { return std::sqrt(static_cast<double>(hiddenCount_) * computeVar()); }

    double computeVar() const {
        const auto sc = static_cast<double>(sideCount_);
        return (sc * sc - 1) / 12;
    }
};

int main() {
    int numDice{};
    int numSides{};
    int maxPos{};
    std::cin >> numDice >> numSides >> maxPos;
    DiceBot bot{maxPos, numSides, numDice};
    std::string input{};
    while (std::cin >> input) {
        if (input == "SETTLE") {
            double price{};
            std::cin >> price;
            bot.update(Settle{.price = price});
            break;
        } else if (input == "QUOTE") {
            std::cout << bot.quote() << '\n';
        } else if (input == "FILL") {
            char side{};
            double price{};
            std::cin >> side >> price;
            bot.update(Fill{.d = (side == 'S' ? Direction::ask : Direction::bid), .price = price});
        } else if (input == "REVEAL") {
            double revealed{};
            std::cin >> revealed;
            bot.update(Reveal{.price = revealed});
        }
    }
    std::cout << bot.profit() << '\n';
}
