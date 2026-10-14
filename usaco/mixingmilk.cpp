#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> milks;
    int total{};
    ifstream in{"mixmilk.in"};
    for (int i{}; i < 3; ++i) {
        int c{};
        int x{};
        in >> c >> x;
        milks.push_back(make_pair(c, x));
        total += x;
    }

    for (int i{}; i < 100; ++i) {
        int bucket{i % 3};
        int next{(i + 1) % 3};
        auto& [cap, contained] = milks[bucket];
        auto& [nextCap, nextContained] = milks[next];

        int poured{min(nextCap - nextContained, contained)};
        nextContained += poured;
        contained -= poured;
    }
    ofstream out{"mixmilk.out"};
    for (auto [_, contained] : milks) { out << contained << '\n'; }
}
