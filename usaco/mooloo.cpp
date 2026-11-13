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
    int nDays{}, fixedCost{}; /* N, K */
    cin >> nDays >> fixedCost;
    vector<ll> daysWatched(nDays);
    for (auto& day : daysWatched) cin >> day;
    /*
     * say we have the following test case:
     * 2 4, N = 2, K = 4
     * 7 9
     * for some given day, we have two choices:
     * - we can subscribe for one day, costing 1 + k
     * - we can subscribe for several days at once
     * we want to subscribe for more days while the following inequality is true
     * (d_current - d_start + 1) + K <= daysCovered * (1 + K)
     */
    const ll dayCost{1 + fixedCost};
    ll totalCost{dayCost};
    ll lastDay{daysWatched.front()};
    for (auto day : daysWatched) {
        if (day - lastDay < dayCost) {
            totalCost += day - lastDay;
        } else {
            totalCost += dayCost;
        }
        lastDay = day;
    }
    cout << totalCost << '\n';
}
