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
    vector<ll> arr(N);
    for (auto& a : arr) cin >> a;
    ll currentSum{};
    for (int i{}; i < N - 1; ++i) {
        currentSum += arr[i];
        cout << currentSum << ' ';
    }
    currentSum += arr[N - 1];
    cout << currentSum;
    return 0;
}
