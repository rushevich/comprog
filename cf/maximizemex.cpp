#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void open_file(string name, bool usaco = false) {
    freopen((name + (usaco ? ".in" : "")).c_str(), "r", stdin);
    freopen((name + (usaco ? ".out" : "")).c_str(), "w", stdout);
}

template<typename T> void out_ans(T&& ans) { cout << std::forward<T>(ans) << '\n'; }

auto solve() -> int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin >> t;
    while (t--) out_ans(solve());
}

auto solve() -> int {
    int n{}, k{};
    ;
    cin >> n >> k;
    if (k == 1) { return n; }

    /* for some rank k, the maximum is  n - k - 1 */
    /*
     * take the case of 0 1 2 3 4 with k = 2
     * that is, we want the 2nd highest value among the mexes
     * note that the maximum mex of any sequence of size m (mex(a_1, a_2, ..., a_m))
     * occurs when every number between 0 and m-1 is present, and we get the mex of m
     * in our case, we have n = 5, and the possible mexes f_1, f_2, f_3, f_4, f_5
     * its important to see that the global max mex is always f_5 since that includes all elements 0...n-1 no matter
     * what you swap.
     * with k = 2, the max mex of rank 2 is clearly 4 -> 0 1 2 3
     */
}
