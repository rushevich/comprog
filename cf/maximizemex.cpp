#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void open_file(string name, bool usaco = false) {
    freopen((name + (usaco ? ".in" : "")).c_str(), "r", stdin);
    freopen((name + (usaco ? ".out" : "")).c_str(), "w", stdout);
}

template<typename T> void out_ans(T&& ans) {
    if (ans.first == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

auto solve() -> pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin >> t;
    while (t--) out_ans(solve());
}

auto solve() -> pair<int, int> {
    int n{}, k{};
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& num : arr) { cin >> num; };
    if (k == 1) { return {-1, -1}; }
    auto first_part_max = max_element(begin(arr), begin(arr) + n - k + 1);
    auto second_part_min = min_element(begin(arr) + n - k + 1, end(arr));
    if (*first_part_max > *second_part_min) {
        return {first_part_max - begin(arr) + 1, second_part_min - begin(arr) + 1};
    }
    return {-1, -1};
}
