#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void solve(ll n) {
    ll total_ways = n * n * (n * n - 1) / 2;
    ll attacking_placements = 4 * (n - 1) * (n - 2);
    cout << total_ways - attacking_placements << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int n{};
    cin >> n;
    for (int i{1}; i <= n; ++i) { solve(i); }
}
