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
    int numTest{};
    cin >> numTest;
    while (numTest--) { solve(); }
}
void solve() {
    int a{};
    int b{};
    int c{};
    cin >> a >> b >> c;
    if (c - b == 1 && b - a == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
