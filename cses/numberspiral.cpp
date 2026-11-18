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
    int nt{};
    cin >> nt;
    while (nt--) { solve(); }
}

void solve() {
    ll r{}, c{};
    cin >> r >> c;
    if (r > c) {
        /* when r is even, (r,0) is equal to r^2 , and we sub c*/
        /* when r is odd, (r,0) is equal to (r-1)^2 + 1 */
        if (r % 2 == 0) cout << (r * r - (c - 1)) << '\n';
        else cout << ((r - 1) * (r - 1) + 1) + (c - 1) << '\n';
    } else {
        /* when c is odd, (0,c) is equal to c^2, and then we sub r */
        /* when c is even, (0,c) is equal to (c-1)^2 + 1 and then we add r */
        if (c % 2 != 0) cout << (c * c) - (r - 1) << '\n';
        else cout << ((c - 1) * (c - 1) + 1) + (r - 1) << '\n';
    }
}
