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
    vector<long long> cows(N);
    for (auto& cow : cows) cin >> cow;
    sort(all(cows));
    struct Tuition {
        long long price{};
        long long profit{};
    };
    Tuition best{};
    for (int i{}; i < N; ++i) {
        const long long tuition = cows[i];
        const long long profitsAt = tuition * (N - i);
        if (profitsAt > best.profit) {
            best.price = tuition;
            best.profit = profitsAt;
        }
    }
    cout << best.profit << ' ' << best.price << '\n';
}
