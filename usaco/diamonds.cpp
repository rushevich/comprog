#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("diamond");
    int N, K;
    in >> N >> K;
    vector<int> dias(N);
    for (int i{}; i < N; ++i) { in >> dias[i]; }
    int most{};
    for (auto x : dias) {
        int count{};
        for (auto y : dias) {
            if (x <= y && y <= x + K) { ++count; }
            most = max(most, count);
        }
    }
    out << most << '\n';
}
