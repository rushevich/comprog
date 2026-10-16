#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("tttt")
    array<array<char, 3>, 3> board{};
    for (int r{}; r < 3; ++r) {
        for (int c{}; c < 3; ++c) { in >> board[r][c]; }
    }
    unordered_set<char> wins;
    set<pair<char, char>> cheatWins;

    auto update = [&wins, &cheatWins](const set<char>& cows) mutable {
        if (cows.size() == 1) {
            wins.insert(*cows.begin());
        } else if (cows.size() == 2) {
            cheatWins.emplace(*cows.begin(), *next(cows.begin()));
        }
    };
    for (int r{}; r < 3; ++r) {
        set<char> cows; // the cows that have used this row
        for (int c{}; c < 3; ++c) { cows.insert(board[r][c]); }
        update(cows);
    }

    for (int c{}; c < 3; ++c) {
        set<char> cows;
        for (int r{}; r < 3; ++r) { cows.insert(board[r][c]); }
        update(cows);
    }
    {
        set<char> cows;
        for (int r{}; r < 3; ++r) { cows.insert(board[r][r]); }
        update(cows);
    }
    {
        set<char> cows;
        for (int r{}; r < 3; ++r) { cows.insert(board[r][2 - r]); }
        // 0, 2    1, 1    2, 0
        update(cows);
    }

    out << wins.size() << '\n' << cheatWins.size() << '\n';
}
