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

    // Essentially, we can say a position differentiates spotted cows from plain ones
    // if the set of genomes for either cow in that position is distinct.
    // We should iterate through both spotted and plain cows for each position at a time and check
    int count{};
    for (int i{}; i < M; ++i) {
        unordered_set<char> spottedGenes;
        for (auto& sCow : spotted) { spottedGenes.insert(sCow[i]); }
        bool distinct{true};
        for (auto& pCow : plain) {
            if (spottedGenes.count(pCow[i])) {
                distinct = false;
                break;
            }
        }
        count += distinct;
    }
    out << count << '\n';
}
