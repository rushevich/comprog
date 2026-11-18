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
    size_t numDeals{}, numQueries{};
    cin >> numDeals >> numQueries;
    vector<ll> deals(numDeals + 1);

    deals[0] = INT_MAX;
    for (size_t d{1}; d <= numDeals; ++d) {
        cin >> deals[d];
        deals[d] = min(deals[d], deals[d - 1] * 2);
    }
    auto calculate_cost = [&deals, numDeals](ll buckets) {
        ll min_cost = 1e18;
        ll cur_cost = 0;
        for (int i{min(30, sci(numDeals - 1))}; i >= 0; --i) {
            ll cur_buckets = 1 << i;
            ll count = buckets / cur_buckets;

            buckets -= count * cur_buckets;
            cur_cost += count * deals[i + 1];

            if (buckets == 0) {
                min_cost = min(min_cost, cur_cost);
            } else {
                /* See if taking one more / overflowing will minimize the cost */
                min_cost = min(min_cost, cur_cost + deals[i + 1]);
            }
        }
        return min_cost;
    };
    for (size_t q{}; q < numQueries; ++q) {
        ll order{};
        cin >> order;
        cout << calculate_cost(order) << '\n';
    }
}
