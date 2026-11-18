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
    char last{'0'};
    string seq;
    cin >> seq;
    int cur{};
    int best{};
    for (int i{}; i < size(seq); ++i) {
        if (seq[i] != last) {
            best = max(best, cur);
            cur = 1;
            last = seq[i];
        } else {
            ++cur;
        }
    }
    cout << max(cur, best) << '\n';
}
