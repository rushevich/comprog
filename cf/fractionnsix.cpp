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

static constexpr array<int, 26> sixarr = [] {
    array<int, 26> arr{};
    arr['s' - 'a'] = 1;
    arr['i' - 'a'] = 1;
    arr['x' - 'a'] = 1;
    return arr;
}();

void solve() {
    int n{};
    // length of p
    int m{};
    // length of q
    cin >> n >> m;
    array<int, 26> pArr{};
    for (int i{}; i < n; ++i) {
        char ch{};
        cin >> ch;
        ++pArr[ch - 'a'];
    }
    array<int, 26> qArr{};
    for (int i{}; i < m; ++i) {
        char ch{};
        cin >> ch;
        ++qArr[ch - 'a'];
    }
    for (int i{}; i < 26; ++i) {
        // Can cancel as many as p and q have in common
        const int cancellable = min(pArr[i], qArr[i]);
        pArr[i] -= cancellable;
        qArr[i] -= cancellable;
        const char ch = 'a' + i;
        if (ch == 'i' || ch == 's' || ch == 'x') continue;
        if (qArr[i] != 0 || pArr[i] != 0) { // denominator must be 0
            cout << "NO\n";
            return;
        }
    }
    cout << (pArr == sixarr ? "YES\n" : "NO\n");
}
