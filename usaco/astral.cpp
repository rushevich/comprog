#include <bits/stdc++.h>
using namespace std;
void solve();
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
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

constexpr auto white = 'W';
constexpr auto black = 'B';
constexpr auto grey = 'G';

void solve() {
    int N{}, rShift{}, dShift{};
    cin >> N >> rShift >> dShift;

    vector<string> grid(N, string(N, '.'));
    for (auto& row : grid) { cin >> row; }

    /* Refers to the original photo */
    vector<vector<bool>> has_star(N, vector<bool>(N));

    for (int r{}; r < N; ++r) {
        for (int c{}; c < N; ++c) {
            if (grid[r][c] != black) continue;
            if (c - rShift < 0 || r - dShift < 0) {
                cout << -1 << '\n';
                return;
            }
            has_star[r][c] = has_star[r - dShift][c - rShift] = true;
        }
    }

    for (int r{}; r < N; ++r) {
        for (int c{}; c < N; ++c) {
            if (grid[r][c] == grey) {
                /* We have already explained this star */
                if (has_star[r][c]) continue;

                /* A shift explains this star */
                if (c >= rShift && r >= dShift && has_star[r - dShift][c - rShift]) continue;

                /* Otherwise, say that there must've been a star */
                /*
                 * This is a greedy choice -> as soon as we reach a not yet explained grey star, we
                 * choose to explain it simply using a star at that point. This yields the local optimal since
                 * the other option is to explain it as a shifted version from before. However, giving a star
                 * the lastest explanation possible will also potentially explain other stars down the line,
                 * globally minimizing the total original stars
                 */
                has_star[r][c] = true;
            }
            /* Contradiction */
            else if (grid[r][c] == white && has_star[r][c]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    int starCount{};
    for (int r{}; r < N; ++r) {
        for (int c{}; c < N; ++c) { starCount += has_star[r][c]; }
    }
    cout << starCount << '\n';
    return;
}
