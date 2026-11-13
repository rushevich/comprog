#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

#define USE_FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
#endif
    int nCows{};
    cin >> nCows;
    vector<int> cows(nCows);
    for (auto& cow : cows) { cin >> cow; }
    vector<int> original(all(cows));
    sort(all(cows));
    int differ{};
    for (int i{}; i < nCows; ++i) {
        if (cows[i] != original[i]) ++differ;
    }

    cout << differ - 1 << '\n';
}
