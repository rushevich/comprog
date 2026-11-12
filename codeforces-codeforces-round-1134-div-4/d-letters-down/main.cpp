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
    /**
     * Approach:
     * We will have a hash map that indicates if one letter has been mapped to
     * another. This way we do not acutally update the string every time.
     * Walk through the letters with 2 pointers, one for the left and one for
     * the right element.
     * If the letters differ at a point, we check if one has already been mapped
     * to another letter. If so, we consider that mapped letter instead. Of
     * these two letters, we find the minimum one. The distance from the higher
     * to the minimum one is the number of operations that we add for this step.
     */

    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

void solve() {
    int sLength{};
    cin >> sLength;
    string str{};
    cin >> str;
    bool swapNeeded[26]{};
    int left{};
    int right{sLength - 1};
    vector<pair<char, char>> mismatches;
    while (left < right) {
        char l = str[left];
        char r = str[right];
        if (l != r) { mismatches.emplace_back(min(l, r), max(l, r)); }
        ++left, --right;
    }

    for (auto [l, r] : mismatches) {
        for (; l + 1 <= r; ++l) { swapNeeded[l - 'a'] = true; }
    }

    int numOps = count(swapNeeded, swapNeeded + 26, true);
    cout << numOps << '\n';
}
