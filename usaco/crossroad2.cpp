#include <bits/stdc++.h>
using namespace std;

#define FILE
static constexpr int num_chars = 52;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
#endif
    string s;
    cin >> s;
    array<int, 26> cowStarts{};
    set<pair<int, int>> pairs;
    memset(cowStarts.data(), -1, cowStarts.size() * sizeof(int));
    for (int i{}; i < num_chars; ++i) {
        char ch = s[i];
        if (cowStarts[ch - 'A'] == -1) {
            cowStarts[ch - 'A'] = i;
            continue;
        } else {
            unordered_set<char> seen;
            for (int pos{cowStarts[ch - 'A'] + 1}; pos < i; ++pos) {
                if (seen.count(s[pos]) > 0) {
                    seen.erase(s[pos]);
                } else {
                    seen.insert(s[pos]);
                }
            }
            for (auto oC : seen) {
                pair<int, int> p{ch, oC};
                if (p.first > p.second) { swap(p.first, p.second); }
                pairs.insert(move(p));
            }
        }
    }
    cout << pairs.size() << '\n';
}
