#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

void solve() {
    int N{}, K{};
    cin >> N >> K;

    // The goal is to go through the entirety of targets and see if we can make
    // up the element at index i using elements from parts

    // We can apply 2 * element + k == target
    // so we can check if ((target - k) / 2) == element
    unordered_map<int, int> parts;
    for (int i{}; i < N; ++i) {
        int num{};
        cin >> num;
        ++parts[num];
    }

    vector<int> targets(N);
    for (auto& target : targets) cin >> target;

    // Part can reach target if it possible to match the parity of the two.
    // We can flip the parity one of two ways, given our operations:
    // if the target is odd, and part is even, we can make it odd by doing
    // part * 2 + k is k is odd
    // if the target is even and the part is odd, we can make it even by doing
    // 2 * part + k if k is even
    const auto targetReachable = [K](int target, int part) {
        const bool targetOdd = target % 2 != 0;
        const bool KOdd = K % 2 != 0;
        const bool partOdd = part % 2 != 0;
        if (partOdd == targetOdd) return true;
        else if (targetOdd && !partOdd && KOdd) return true;
        else if (!targetOdd && partOdd && !KOdd) return true;
        return false;
    };
    int covered{};
    for (const auto& target : targets) {
        int partUsed{-1};
        for (const auto& [part, freq] : parts) {
            if (targetReachable(target, part)) {
                partUsed = part;
                break;
            }
        }
        if (partUsed != -1) {
            ++covered;

            if (--parts[partUsed] == 0) { parts.erase(partUsed); }
        }
    }
    cout << (covered == N ? "YES\n" : "NO\n");
}
