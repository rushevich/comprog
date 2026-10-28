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
    cin >> n;
    vector<int> arr(n);
    for (auto& num : arr) cin >> num;

    sort(all(arr));
    auto newEnd = unique(arr.begin(), arr.end());
    cout << newEnd - arr.begin() << '\n';
}
