#include <bits/stdc++.h>
using namespace std;

#define USE_FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif
    array<string, 8> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    unordered_map<string, int> cowToI;
    for (int i{}; i < 8; ++i) { cowToI.emplace(cows[i], i); }
    int nRules{};
    cin >> nRules;
    struct Rule {
        int cowA{};
        int cowB{};
    };
    vector<Rule> rules(nRules);
    for (auto& r : rules) {
        string cowA, cowB, dummy;
        cin >> cowA >> dummy >> dummy >> dummy >> dummy >> cowB;
        r.cowA = cowToI[cowA];
        r.cowB = cowToI[cowB];
    }
    string order{"01234567"};
    vector<string> results;
    do {
        bool good{true};
        for (const auto& [cowA, cowB] : rules) {
            const int aPos = order.find('0' + cowA);
            const int bPos = order.find('0' + cowB);
            if (abs(aPos - bPos) != 1) {
                good = false;
                break;
            }
        }
        if (good) { break; }
    } while (next_permutation(order.begin(), order.end()));
    for (char c : order) {
        int i = c - '0';
        cout << cows[i] << '\n';
    }
    return 0;
}
