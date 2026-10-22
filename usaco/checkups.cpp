#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int N{};
    cin >> N;

    vector<int> cowSpecies(N);
    for (auto& s : cowSpecies) cin >> s;
    vector<int> vetOrder(N);
    for (auto& o : vetOrder) cin >> o;

    vector<int> result(N + 1);
    int initialMatches{};
    for (int i{}; i < N; ++i) { initialMatches += cowSpecies[i] == vetOrder[i]; }

    auto updateContributions = [&cowSpecies, &vetOrder](int& current, int l, int r) mutable {
        current -= (cowSpecies[l] == vetOrder[l]);
        current -= (cowSpecies[r] == vetOrder[r]);
        current += (cowSpecies[r] == vetOrder[l]);
        current += (cowSpecies[l] == vetOrder[r]);
    };
    // First search all the odd ranges
    for (int i{}; i < N; ++i) {
        int currentContribution{initialMatches};
        ++result[currentContribution];
        int l{i - 1};
        int r{i + 1};
        while (l >= 0 && r < N) {
            updateContributions(currentContribution, l, r);
            ++result[currentContribution];
            --l;
            ++r;
        }
    }
    for (int i{}; i < N; ++i) {
        int currentContribution{initialMatches};
        int l{i};
        int r{i + 1};
        while (l >= 0 && r < N) {
            updateContributions(currentContribution, l, r);
            ++result[currentContribution];
            --l;
            ++r;
        }
    }

    for (int c : result) { cout << c << '\n'; }
}
