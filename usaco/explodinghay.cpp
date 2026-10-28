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
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
#endif
    int nBales{};
    cin >> nBales;
    vector<long long> bales(nBales);
    for (auto& b : bales) cin >> b;

    sort(all(bales));

    const auto countExplosions = [](int pos, const vector<long long>& arr) -> int {
        const long long origin = arr[pos];
        long long minReachable{origin - 1};
        int currentRadius{1};
        int explosions{1};
        int goingLeft{pos - 1};
        while (goingLeft >= 0) {
            long long nextMinReachable{-1};
            while (goingLeft >= 0 && arr[goingLeft] >= minReachable) {
                ++explosions;
                nextMinReachable = arr[goingLeft];
                --goingLeft;
            }
            if (nextMinReachable == -1) break;
            else minReachable = nextMinReachable - (++currentRadius);
        }

        long long maxReachable{origin + 1};
        currentRadius = 1;
        int goingRight{pos + 1};
        while (goingRight < size(arr)) {
            long long nextMaxReachable{-1};
            while (goingRight < size(arr) && arr[goingRight] <= maxReachable) {
                ++explosions;
                nextMaxReachable = arr[goingRight];
                ++goingRight;
            }
            if (nextMaxReachable == -1) break;
            else maxReachable = nextMaxReachable + (++currentRadius);
        }
        return explosions;
    };

    int maxExplosions{1};
    for (int i{}; i < size(bales); ++i) { maxExplosions = max(maxExplosions, countExplosions(i, bales)); }
    cout << maxExplosions << '\n';
}
