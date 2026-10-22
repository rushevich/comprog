#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("cownomics");
    // 3 8
    // AATCCCAT
    // GATTGCAA
    // GGTCGCAA

    // ACTCCCAG
    // ACTCGCAT
    // ACTTCCAT
    int N{}, M{};
    in >> N >> M;
    vector<string> spotted(N, string(M, ' '));
    for (int i{}; i < N; ++i) {
        for (int j{}; j < M; ++j) { in >> spotted[i][j]; }
    }
    vector<string> plain(N, string(M, ' '));
    for (int i{}; i < N; ++i) {
        for (int j{}; j < M; ++j) { in >> plain[i][j]; }
    }

    int count{};
    unordered_map<char, int> mp{{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
    const auto serialize = [&mp](char a, char b, char c) { return (mp[a] * 16 + mp[b] * 4 + mp[c]); };
    for (int i{}; i < M; ++i) {
        for (int j{i + 1}; j < M; ++j) {
            for (int k{j + 1}; k < M; ++k) {
                unordered_set<int> threeSp;
                for (const auto& str : spotted) { threeSp.insert(serialize(str[i], str[j], str[k])); }
                bool good{true};
                for (const auto& str : plain) {
                    if (threeSp.count(serialize(str[i], str[j], str[k])) > 0) {
                        good = false;
                        break;
                    }
                }
                count += good;
            }
        }
    }
    out << count << '\n';
}
