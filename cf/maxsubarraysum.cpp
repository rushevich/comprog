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
    // Kadane’s algorithm
    int n{};
    cin >> n;
    ll result{INT_MIN};
    ll current{INT_MIN};
    for (int i{}; i < n; ++i) {
        ll num{};
        cin >> num;
        current = max(current + num, num);
        result = max(result, current);
    }
    cout << result << '\n';
}
