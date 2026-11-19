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
    open_file("guess", true);
    int nAnimals{};
    cin >> nAnimals;
    unordered_map<string, unordered_set<string>> animals;
    for (int i{}; i < nAnimals; ++i) {
        string animal;
        cin >> animal;
        animals[animal] = {};
        int nTraits{};
        cin >> nTraits;
        while (nTraits--) {
            string trait;
            cin >> trait;
            animals[animal].insert(trait);
        }
    }

    int max_shared{};
    for (const auto& [animal, traits] : animals) {
        for (const auto& [other_animal, other_traits] : animals) {
            if (other_animal == animal) continue;
            int count{};
            for (const auto& t : traits) { count += other_traits.count(t); }
            max_shared = max(max_shared, count);
        }
    }
    cout << max_shared + 1 << '\n';
}

void solve() {}
