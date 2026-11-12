#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

#define USE_FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
#endif
    pair<int, int> fj;
    pair<int, int> bessie;
    cin >> fj.first >> fj.second >> bessie.first >> bessie.second;
    auto intervals = vector{fj, bessie};
    sort(all(intervals)); /* orders by start */
    auto& [start, end] = intervals.front();
    auto& [nextStart, nextEnd] = intervals.back();
    if (nextStart <= end) {
        end = max(end, nextEnd);
        intervals.pop_back();
    }
    int covered{};
    for (const auto& [start, end] : intervals) { covered += end - start; }

    cout << covered << '\n';
}
