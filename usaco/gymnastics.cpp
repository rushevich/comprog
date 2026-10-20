#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("gymnastics");
    int K, N;
    in >> K >> N;
    vector<vector<int>> trials(K, vector<int>(N));
    // N cows  { 1 2 3 4} - > cow 0 got first place, cow 1 got second, etc.
    for (int i{}; i < K; ++i) {
        for (int j{}; j < N; ++j) {
            int cow{};
            in >> cow;
            trials[i][cow - 1] = j;
        }
    }
    int pairs{};
    for (int cow{}; cow < N; ++cow) {
        for (int otherCow{}; otherCow < N; ++otherCow) {
            if (cow == otherCow) continue;
            bool good{true};
            for (int trial{}; trial < K; ++trial) {
                if (trials[trial][cow] > trials[trial][otherCow]) {
                    good = false;
                    break;
                }
            }
            pairs += good;
        }
    }
    out << pairs << '\n';
}
