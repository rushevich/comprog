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
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (N == 4) {
        for (int i{2}; i <= N; i += 2) { cout << i << ' '; }
        for (int i{1}; i <= N; i += 2) { cout << i << ' '; }
    } else {
        for (int i{1}; i <= N; i += 2) { cout << i << ' '; }
        for (int i{2}; i <= N; i += 2) { cout << i << ' '; }
    }
}
