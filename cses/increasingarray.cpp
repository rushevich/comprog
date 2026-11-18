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
    int N{};
    cin >> N;
    ll moves{};
    ll last{};
    for (int i{}; i < N; ++i) {
        ll x{};
        cin >> x;
        if (last == 0) {
            last = x;
            continue;
        }
        if (x < last) {
            moves += last - x;
        } else {
            last = x;
        }
    }
    cout << moves << '\n';
}
