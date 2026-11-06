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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
#endif
    int nCows{};
    cin >> nCows;
    string original;
    cin >> original;
    for (int i{}; i < nCows; ++i) {
        char ch{};
        cin >> ch;
        if (ch != original[i]) { original[i] = '#'; }
    }
    int numFlips{};
    int start{-1};
    // 7
    // GHHHGHH
    // HHGGGHH
    // -> #H##GHH
    for (int i{}; i < nCows; ++i) {
        if (original[i] == '#') {
            start = (start == -1) ? i : start;
        } else {
            numFlips += (start != -1);
            start = -1;
        }
    }
    cout << numFlips << '\n';
}
