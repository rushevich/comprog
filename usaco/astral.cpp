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
    int N{}, A{}, B{};
    cin >> N >> A >> B;
    vector<vector<int>> grid(N, vector<int>(N));
    /*
     * We build the image. W goes to 0, G goes to 1, B goes to 2
     */
    int nStars{};
    for (size_t i{}; i < N; ++i) {
        for (size_t j{}; j < N; ++j) {
            char ch{};
            cin >> ch;
            grid[i][j] = [&ch] {
                if (ch == 'W') return 0;
                if (ch == 'G') return 1;
                return 2;
            }();
            nStars += grid[i][j] > 0;
        }
    }
    if (A == 0 && B == 0) {
        cout << nStars << '\n';
        return;
    }
    int originals{};
    const auto invalid = [N](int r, int c) { return (r < 0 || r >= N || c < 0 || c >= N); };

    for (int r{N - 1}; r >= 0; --r) {
        for (int c{N - 1}; c >= 0; --c) {
            /* White cells don't tell us anything meaningful */
            if (grid[r][c] == 0) continue;
            if (grid[r][c] == 1) {
                if (invalid(r - B, c - A)) {
                    grid[r][c] = 0;
                    ++originals;
                    continue;
                }
                if (auto& og = grid[r - B][c - A]; og == 1) {
                    grid[r][c] = og = 0;
                    ++originals;
                    continue;
                }
            } else {
                /* The case where grid[r][c] is black */
                if (invalid(r - B, c - A) || grid[r - B][c - A] == 0) {
                    cout << -1 << '\n';
                    return;
                }
                originals += 2;
                --grid[r - B][c - A];
                grid[r][c] = 0;
            }
        }
    }
    cout << originals << '\n';
}
