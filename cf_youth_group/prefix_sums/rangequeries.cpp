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
    size_t n{};
    cin >> n;
    size_t q{};
    cin >> q;
    vector<ll> arr(n);
    vector<ll> prefix(n + 1);
    for (size_t i{1}; auto& a : arr) {
        cin >> a;
        prefix[i] = a + prefix[i - 1];
        ++i;
    }

    for (size_t iQ{}; iQ < q; ++iQ) {
        size_t l{}, r{};
        cin >> l >> r;
        cout << (prefix[r] - prefix[l - 1]) << '\n';
    }
    return 0;
}
