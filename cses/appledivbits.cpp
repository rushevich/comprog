#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif

    int n{};
    cin >> n;
    using ll = long long;
    vector<ll> weights(n);
    for (auto& w : weights) { cin >> w; }
    ll minDiff{INT_MAX};
    for (int m{}; m < (1 << n); ++m) {
        ll s1{}, s2{};
        for (int i{}; i < n; ++i) {
            if (m & (1 << i)) s2 += weights[i];
            else s1 += weights[i];
        }
        minDiff = min(minDiff, abs(s1 - s2));
    }
    cout << minDiff << '\n';
    return 0;
}
