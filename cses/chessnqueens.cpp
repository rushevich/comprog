#include <bits/stdc++.h>
using namespace std;

static constexpr int N = 8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    array<array<bool, N>, N> blocked{{}};
    for (int r{}; r < N; ++r) {
        for (int c{}; c < N; ++c) {
            char ch{};
            cin >> ch;
            blocked[r][c] = ch == '*';
        }
    }

    array<int, N> queens{};
    // queens represents the queens distribution among the rows
    // given that they are separated by one column at least
    // queens {0, 2, 1, 3}:
    //   0 1 2 3
    // 0 q . . .
    // 1 . . q .
    // 2 . q . .
    // 3 . . . q
    // so queens[c] = x says that the queen in column c is at row x
    iota(queens.begin(), queens.end(), 0);
    int numArrangements{};
    do {
        bool good{true};
        for (int c{}; c < N; ++c) {
            if (blocked[queens[c]][c]) {
                good = false;
                break;
            }
        }

        // then we should check the diagonals
        array<bool, 2 * N - 1> diag1{};

        for (int c{}; c < N; ++c) {
            const int r{queens[c]};
            if (diag1[r + c]) {
                good = false;
                break;
            }
            diag1[r + c] = true;
        }
        array<bool, 2 * N - 1> diag2{};
        for (int c{}; c < N; ++c) {
            const int r{queens[c]};
            if (diag2[r - c + N - 1]) {
                good = false;
                break;
            }
            diag2[r - c + N - 1] = true;
        }
        if (good) ++numArrangements;
    } while (next_permutation(queens.begin(), queens.end()));
    cout << numArrangements << '\n';
}
