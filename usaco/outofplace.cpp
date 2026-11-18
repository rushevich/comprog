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
    open_file("outofplace", true);
    int nCows{};
    cin >> nCows;
    vector<int> cows(nCows);
    for (auto& cow : cows) { cin >> cow; }
    vector<int> sortedCows(cows);
    sort(all(sortedCows));
    int diffs{};
    for (int i{}; i < nCows; ++i) { diffs += sortedCows[i] != cows[i]; }
    cout << diffs - 1 << '\n';
}

void solve() {}
