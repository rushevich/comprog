#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))
#define clearVec(x) memset((x).data(), 0, (x).size() * sizeof(typename decltype((x))::value_type))

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int nT{};
    cin >> nT;
    while (nT--) { solve(); }
}

#define int long long

auto calcDiff = [](const auto& arr) {
    int diff{};
    int prefix{};
    for (int i{}; i < size(arr); ++i) {
        diff += arr[i] * i - prefix;
        prefix += arr[i];
    }
    return diff;
};

void solve() {
    int n{}; // 4
    cin >> n;
    int m{};  // numbers on one card
    cin >> m; // 3

    // First gather all into what is effectively just the provided input "grid"
    // Then iterate for every numCount with a vector sized at nCards.
    vector<vector<int>> cards(n, vector<int>(m));
    for (int r{}; r < n; ++r) {
        for (int c{}; c < m; ++c) {
            int in{};
            cin >> in;
            cards[r][c] = in;
        }
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int totalDiff{}; // = 0
    vector<int> cardColumn(n);
    for (int curCol{}; curCol < m; ++curCol) {
        for (int curRow{}; curRow < n; ++curRow) { cardColumn[curRow] = cards[curRow][curCol]; }
        // 1 3 1 4
        sort(all(cardColumn)); // 1 1 3 4
        totalDiff += calcDiff(cardColumn);
    }
    cout << totalDiff << '\n';
}
