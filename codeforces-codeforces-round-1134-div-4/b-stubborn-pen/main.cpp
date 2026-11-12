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
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}

void solve() {
    int sLength{};
    cin >> sLength;
    string target{};
    cin >> target;
    char current{'R'};
    auto switchColor = [](char& ch) {
        if (ch == 'R') {
            ch = 'B';
        } else {
            ch = 'R';
        }
    };
    int swaps{};
    for (auto& letter : target) {
        if (letter != current) {
            ++swaps;
            switchColor(current);
        }
        switchColor(current);
    }
    cout << swaps << '\n';
}
