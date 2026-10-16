#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N{};
    int U{};
    cin >> N >> U;
    vector<vector<char>> p(N, vector<char>(N));
    for (int r{}; r < N; ++r) {
        for (int c{}; c < N; ++c) { cin >> p[r][c]; }
    }
    int diff{};
    auto cost = [&p, N](int r, int c) -> int {
        int k =
            (p[r][c] == '#') + (p[r][N - 1 - c] == '#') + (p[N - 1 - r][c] == '#') + (p[N - 1 - r][N - 1 - c] == '#');
        return min(k, 4 - k);
    };

    int diffTotal{};
    for (int r{}; r < N / 2; ++r) {
        for (int c{}; c < N / 2; ++c) { diffTotal += cost(r, c); }
    }
    cout << diffTotal << '\n';
    for (int i{}; i < U; ++i) {
        int r{};
        int c{};
        cin >> r >> c;
        r--, c--;
        diffTotal -= cost(r, c);
        p[r][c] = (p[r][c] == '#') ? '.' : '#';
        diffTotal += cost(r, c);
        cout << diffTotal << '\n';
    }
    return 0;
}
