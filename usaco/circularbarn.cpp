#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("cbarn");
    int n{};
    in >> n;
    vector<int> caps(n);
    for (int i{}; i < n; ++i) { in >> caps[i]; }
    // 4 7 8 6 4
    // 7 is supposedly the best
    // if going from 7, 4 will go all the way around, -> 16
    // then 8 for 8.
    // then 6 + 6
    // then 4 + 4 + 4
    // = 4 + 8 + 12 + 12 =

    int minDist{INT_MAX};
    for (int entry{}; entry < n; ++entry) {
        int totalDistance{};
        for (int dest{}; dest < n; ++dest) {
            if (dest == entry) { continue; }
            const int cows = caps[dest];
            const int doors = dest - entry < 0 ? dest + n - entry : dest - entry;
            totalDistance += cows * doors;
            // dest = 0, cows = 4, entry = 1
            // -> dest - entry = - 1 ->  0 + 5 - 1 = 4
        }
        minDist = min(minDist, totalDistance);
    }
    out << minDist << '\n';

    return 0;
}
