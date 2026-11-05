#include <bits/stdc++.h>
#include <ranges>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define rall(x) rbegin((x)), rend((x))
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
    vector<ll> a(N);
    for (auto& elem : a) cin >> elem;
    vector<ll> b(N);
    for (auto& elem : b) cin >> elem;
    // the factor of frequency among all subarrays is tied to the elements position in array ’a’
    int curIndex{};
    auto aWeights = ranges::to<vector<ll>>(a | views::transform([&curIndex, N](ll x) mutable {
                                               const int i = curIndex++;
                                               return x * (i + 1) * (N - i);
                                           }));
    sort(all(aWeights));
    sort(rall(b));
    ll result{};
    for (int i{}; i < N; ++i) { result += b[i] * aWeights[i]; }
    cout << result << '\n';
}
