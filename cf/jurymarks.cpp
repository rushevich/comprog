#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int nJury{}, nRemembered{}; // nJury = k
    cin >> nJury >> nRemembered;
    ll currentPrefix{};
    cin >> currentPrefix;
    unordered_set<ll> prefixes;
    prefixes.insert(currentPrefix);
    for (size_t i{1}; i < nJury; ++i) {
        ll score{};
        cin >> score;
        prefixes.insert(currentPrefix += score);
    }
    vector<ll> recalledMarks(nRemembered);
    for (auto& mark : recalledMarks) { cin >> mark; }

    unordered_set<ll> possibleStarts;
    const ll b1 = recalledMarks.front();
    for (auto pre : prefixes) { possibleStarts.insert(b1 - pre); }

    int validStartCount{};
    for (auto x : possibleStarts) {
        bool good{true};
        for (auto b : recalledMarks) {
            if (!(good = prefixes.contains(b - x))) { break; }
        }
        validStartCount += good;
    }

    cout << validStartCount << '\n';

    // We go through each recalled mark:
    // for some recalled mark M, we then march through the juryScores that are in chronological order
    // at for some jury mark at time i (j_i), we assume that M was recalled after time i
    // that is M = initial_mark + sum(0 to i, jury_mark_i).
    // if we consider that M actually did occur after the jury_i mark, then we can write
    // M - sum(...) = initial_mark
    // Every time we encounter some new initial_mark, we increase the frequency of this mark in
    // some unordered_map. map[initial_mark] = f --> f possible remembered values coincide with this
    // initial_mark. this works because recalledMarks is not necessarily ordered

    // The better approach: a valid start must coincide with every recalled mark, so we can generate the possible starts
    // from an arbitrarily selected recalled mark (say b_1). We can then exploit the problem’s shape:
    // we know some candidate start ~x~ is valid if for every b_i (recalled mark), the prefix of b_i - x exists
}
