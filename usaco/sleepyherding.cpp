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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif
    ll B{}, E{}, M{}; // Bessie, Elsie, Mildred
    cin >> B >> E >> M;
    if (max({B, E, M}) - min({B, E, M}) == 2) {
        cout << 0 << '\n' << 0 << '\n';
        return 0;
    }
    if (abs(B - E) == 2 || abs(E - M) == 2 || abs(B - M) == 2) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
    array<ll, 3> cows{B, E, M};
    sort(all(cows));
    cout << max(cows[1] - cows[0] - 1, cows[2] - cows[1] - 1) << '\n';
}
