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
    int n{}, q{};
    cin >> n >> q;
    vector<int> nums(n);
    vector<int> prefix(n + 1);
    for (int i{1}; auto& num : nums) {
        cin >> num;
        prefix[i] = prefix[i - 1] ^ num;
        ++i;
    }
    for (int i{}; i < q; ++i) {
        int l{}, r{};
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l - 1]) << '\n';
    }
    return 0;
}
