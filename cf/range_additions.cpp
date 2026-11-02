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
    int n{};
    int m{};
    cin >> n >> m;
    vector<ll> nums(n);
    for (auto& num : nums) cin >> num;
    vector<ll> diffs(n + 1);
    for (int i{}; i < m; ++i) {
        int l{}, r{}, x{};
        cin >> l >> r >> x;
        diffs[l - 1] += x;
        diffs[r] -= x;
    }

    ll curDelta{};
    for (int i{}; i < n; ++i) {
        curDelta += diffs[i];
        cout << (nums[i] + curDelta) << ' ';
    }
    return 0;
}
