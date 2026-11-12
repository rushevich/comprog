#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    /*
     * 5 2
     * 1 2 3 4 5
     */
    /* for 3, it is at index 2, and k = 2
     * it can add min (k, index)
     * for 2 it is at index 1 and k = 2, it can add just 1
     */
    /*  how much does some pile p[i] add to the last pile? */
    /*
     *
     */

    /*
     * --> 1 2 8 9 0
     * --> 1 11 17 0 0
     * --> 18 28 0 0 0
     * --> 46
     */

    /**
     * 3 1
     * 2 5 2
     * --> 2 7 0
     * --> 9 0 0
     */

    /**
     * 3 2
     * 0 0 1
     * --> 1 1 0
     * --> 2 0 0
     */
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

void solve() {
    int nPiles{}, k{};
    cin >> nPiles >> k;
    vector<ll> piles(nPiles);
    for (auto& p : piles) cin >> p;
    char curPlayer{'A'}; /* starts with Alice */
    /* swaps on piles with odd # of rocks */
    auto swapPlayer = [](char& cur) { cur = (cur == 'A') ? 'B' : 'A'; };
    ll pref{};
    for (int i{nPiles - 1}; i > 0; --i) {
        pref += (piles[i] * static_cast<ll>(min(k, i)));
        if (pref % 2 != 0) swapPlayer(curPlayer);
    }
    piles[0] += pref;
    /* if the final is odd, then the currentPlayer wins */
    if (piles[0] % 2 != 0) {
        cout << (curPlayer == 'A' ? "Alice\n" : "Bob\n");
    } else {
        cout << (curPlayer == 'A' ? "Bob\n" : "Alice\n");
    }
}
