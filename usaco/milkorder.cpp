#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void open_file(string name, bool usaco = false) {
    freopen((name + (usaco ? ".in" : "")).c_str(), "r", stdin);
    freopen((name + (usaco ? ".out" : "")).c_str(), "w", stdout);
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    open_file("milkorder", true);

    int nCows{}, nHierarchy{}, nSpecific{};
    cin >> nCows >> nHierarchy >> nSpecific;

    vector<int> hierarchy(nHierarchy);
    for (auto& h : hierarchy) {
        cin >> h;
        --h;
    };

    vector<pair<int, int>> spec_pos(nSpecific);
    for (auto& [cow, pos] : spec_pos) {
        cin >> cow >> pos;
        --cow, --pos; /* number cows from 0 -> N-1 */
    }

    vector<int> cows(nCows, -1);   /* cows[i] = -1 -> no cow here yet */
    vector<int> placed(nCows, -1); /* index of cows placement or -1 if not placed */
    /* Specific positions -> strict constraint */
    for (const auto& [cow, pos] : spec_pos) {
        cows[pos] = cow;
        placed[cow] = pos;
    }
}

void solve() {}
