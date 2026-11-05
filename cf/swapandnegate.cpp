#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

void solve() {
    int n{};
    cin >> n;
    vector<ll> a(n);
    for (auto& elem : a) { cin >> elem; }
    if (n == 1) {
        cout << a.front() << '\n';
        return;
    }
    // taking the swap at i is a bad choice only if the swap of i + 1 and i + 2 is better
    for (int i{}; i < n - 2; ++i) { int th }
}
