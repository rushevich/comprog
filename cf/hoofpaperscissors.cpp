#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int n{};
    cin >> n;
    vector<int> hWins(n + 1); // hWins[i] = number of wins if using only hoof
                              // with i turns
    vector<int> pWins(n + 1);
    vector<int> sWins(n + 1);
    auto update = [&hWins, &pWins, &sWins](char move) -> vector<int>& {
        // Hoof beats scissors, scissors beats paper, paper beats hoof
        switch (move) {
        case 'H': return pWins;
        case 'S': return hWins;
        case 'P': return sWins;
        default: throw std::logic_error("Unhandled opponent input.");
        }
    };
    for (int i{1}; i <= n; ++i) {
        char opp{};
        cin >> opp;
        hWins[i] = hWins[i - 1];
        sWins[i] = sWins[i - 1];
        pWins[i] = pWins[i - 1];

        auto& winner = update(opp);
        winner[i] += 1;
    }
    int best{};
    for (int i{0}; i <= n; ++i) {
        // In this case, i represents the number of elements we use in the first half
        int firstHalf = max({hWins[i], pWins[i], sWins[i]});
        int secondHalf = max({hWins[n] - hWins[i], pWins[n] - pWins[i], sWins[n] - sWins[i]});
        best = max(best, firstHalf + secondHalf);
    }
    cout << best << '\n';
}
