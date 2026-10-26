#include <bits/stdc++.h>
using namespace std;

int nHands{};
constexpr int cardCount = 4;
vector<int> results;
using Hand = array<int, 4>;
vector<Hand> hands;
vector<int> currentPerm;

// does x <op> y
int doOp(int op, int x, int y) {
    if (x == INT_MIN || y == INT_MIN) return INT_MIN;
    switch (op) {
    case 0: return x + y; break;
    case 1: return x - y; break;
    case 2: return x * y; break;
    case 3:
        return (y != 0 && x % y == 0) ? x / y : INT_MIN; // sentinel.
        break;
    default: return INT_MIN;
    }
}

void solve(const size_t handIdx) {
    auto& curHand = hands[handIdx];
    if (currentPerm.size() == 4) {
        // try all combinations of operands
        for (int op1{}; op1 < 4; ++op1) {
            for (int op2{}; op2 < 4; ++op2) {
                for (int op3{}; op3 < 4; ++op3) {
                    // 2 possible forms :
                    // - (((ab)c)d)
                    // - ((ab)(cd))
                    int result1{doOp(op1, currentPerm[0], currentPerm[1])};
                    result1 = doOp(op2, result1, currentPerm[2]);
                    result1 = doOp(op3, result1, currentPerm[3]);
                    if (result1 != INT_MIN && result1 <= 24) { results[handIdx] = max(results[handIdx], result1); }

                    int result2{doOp(op1, currentPerm[0], currentPerm[1])};
                    int result2Intermediate{doOp(op2, currentPerm[2], currentPerm[3])};
                    result2 = doOp(op3, result2, result2Intermediate);
                    if (result2 != INT_MIN && result2 <= 24) { results[handIdx] = max(results[handIdx], result2); }
                }
            }
        }
    } else {
        for (int i{}; i < cardCount; ++i) {
            const int val = curHand[i];
            if (val == -1) continue; // skip already-visited values
            curHand[i] = -1;
            currentPerm.push_back(val);
            solve(handIdx);
            curHand[i] = val;
            currentPerm.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    cin >> nHands;
    results.resize(nHands);
    std::memset(results.data(), -1, results.size() * sizeof(int));

    hands.resize(nHands);
    for (auto& h : hands) { cin >> h[0] >> h[1] >> h[2] >> h[3]; }

    for (int i{}; i < nHands; ++i) {
        solve(i);
        cout << results[i] << '\n';
    }
}
