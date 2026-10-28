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
    const int nPeople{n * 2};
    vector<int> weights(nPeople);
    for (auto& w : weights) cin >> w;

    auto calcInstability = [](const auto& arr, int exclude1, int exclude2) {
        int instability{};
        int prevWeight{};
        for (int i{}; i < arr.size(); ++i) {
            if (i == exclude1 || i == exclude2) continue;
            if (prevWeight == 0) {
                prevWeight = arr[i];
            } else {
                instability += abs(prevWeight - arr[i]);
                prevWeight = 0;
            }
        }
        return instability;
    };
    sort(all(weights));
    int bestInst{INT_MAX};
    for (int i{}; i < nPeople; ++i) {
        for (int j{i + 1}; j < nPeople; ++j) { bestInst = min(bestInst, calcInstability(weights, i, j)); }
    }
    cout << bestInst << '\n';
}
