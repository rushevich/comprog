#include <bits/stdc++.h>
using namespace std;

#define USE_FILE
constexpr int nBuckets = 10;

vector<int> firstBuckets(nBuckets);  // buckets @ the first barn
vector<int> secondBuckets(nBuckets); // buckets @ the secodn barn
unordered_set<int> possibleContained;
constexpr int nDays = 5;

// Monday -> 0
// Tuesday -> 1
// Wednesday -> 2
// Thursday -> 3
// Friday -> 4
// next iter -> 5, measure
// on odd # days, he takes from barn 1 and puts in barn 2
// on even # days, he takes from barn 2 and puts in barn 1
void solve(int day = 1, int milkStored = 1000) { // no milk is carried on Monday
    if (day == 5) {
        possibleContained.insert(milkStored);
        return;
    }
    auto& takingFrom = day % 2 != 0 ? firstBuckets : secondBuckets;
    auto& movingTo = day % 2 != 0 ? secondBuckets : firstBuckets;
    for (int i{}; i < takingFrom.size(); ++i) {
        const int bucket = takingFrom[i];
        takingFrom.erase(takingFrom.begin() + i);
        movingTo.push_back(bucket);
        solve(day + 1, day % 2 != 0 ? milkStored - bucket : milkStored + bucket);
        takingFrom.insert(takingFrom.begin() + i, bucket);
        movingTo.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
#endif
    for (auto& f : firstBuckets) { cin >> f; }
    for (auto& s : secondBuckets) { cin >> s; }
    // after FJ carries a bucket from firstBarn --> secondBarn, that bucket now becomes available for secondBarn
    // and vice versa
    solve();
    cout << possibleContained.size() << '\n';
}
