#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
#endif
    unordered_map<string, unordered_set<string>> animalTraits;
    int N{};
    cin >> N;
    for (int i{}; i < N; ++i) {
        string animal;
        cin >> animal;
        int K{};
        cin >> K;
        unordered_set<string> traits;
        for (int j{}; j < K; ++j) {
            string t;
            cin >> t;
            traits.insert(t);
        }
        animalTraits.emplace(move(animal), move(traits));
    }
    // countShared algorithm: for each trait that animalB has, check if animalA also has that trait.
    // If so, add 1 to the count
    auto countShared = [&animalTraits](const string& a, const string& b) {
        int count{};
        auto& aSet = animalTraits[a];
        for (const auto& trait : animalTraits[b]) { count += (aSet.count(trait) > 0); }
        return count;
    };
    int maxShared{};
    for (const auto& [animalA, _] : animalTraits) {
        for (const auto& [animalB, _] : animalTraits) {
            if (&animalA == &animalB) continue;
            maxShared = max(maxShared, countShared(animalA, animalB));
        }
    }
    cout << (maxShared + 1) << '\n';
}
