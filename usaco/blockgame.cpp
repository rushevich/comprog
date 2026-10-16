#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("blocks");

    int N{};
    in >> N;
    array<int, 26> freqs{};

    for (int i{}; i < N; ++i) {
        string top;
        string bot;
        in >> top >> bot;
        array<int, 26> topFreq{};
        array<int, 26> botFreq{};
        for (auto c : top) { ++topFreq[c - 'a']; }
        for (auto c : bot) { ++botFreq[c - 'a']; }
        for (int i{}; i < 26; ++i) { freqs[i] += max(topFreq[i], botFreq[i]); }
    }
    for (auto i : freqs) { out << i << '\n'; }
    return 0;
}
