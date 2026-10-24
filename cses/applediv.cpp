#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int idx, ll sum1, ll sum2);
int nApples;
vector<long long> weights;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    cin >> nApples;
    weights.resize(nApples);
    long long total{};
    for (auto& w : weights) { cin >> w; }

    cout << solve(0, 0, 0) << '\n';
}

ll solve(int idx, ll sum1, ll sum2) {
    if (idx == nApples) return abs(sum1 - sum2);

    return min(solve(idx + 1, sum1 + weights[idx], sum2), solve(idx + 1, sum1, sum2 + weights[idx]));
}
