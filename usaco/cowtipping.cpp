#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

#define USE_FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
#endif
    int N{};
    cin >> N;
    vector<vector<int>> tipped(N, vector<int>(N));
    /* 1 = tipped, 0 = not tipped */
    for (auto& row : tipped) {
        for (auto& cell : row) {
            char ch{};
            cin >> ch;
            cell = ch == '1';
        }
    }
    /* Flips all the cells from the upper-left most corner to the cell at r,c,
     * and returns the number of zeros now in the grid
     */
    auto flip = [](auto& grid, int r, int c) -> void {
        /*
         * If a cell goes from true -> false, subtract 1 from tipped
         */
        for (int i{}; i <= r; ++i) {
            for (int j{}; j <= c; ++j) { grid[i][j] = grid[i][j] == 0 ? 1 : 0; }
        }
    };
    int curR{N - 1};
    int curC{N - 1};
    int nFlips{};
    while (curR >= 0 && curC >= 0) {
        if (tipped[curR][curC] == 1) {
            flip(tipped, curR, curC);
            ++nFlips;
        }
        if (curR != curC && tipped[curC][curR] == 1) {
            flip(tipped, curC, curR);
            ++nFlips;
        }
        if (curC > 0) {
            --curC;
        } else {
            --curR;
            curC = curR;
        }
    }
    cout << nFlips << '\n';
}
