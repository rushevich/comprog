#include <bits/stdc++.h>
using namespace std;
int maxNum{};
vector<int> perm;
vector<int> result;

void solve() {
    if (perm.empty()) {
        for (int i : result) { cout << i << '\n'; }
        exit(0);
    }
    for (int i{static_cast<int>(perm.size() - 1)}; i >= 0; --i) {
        auto val = perm[i];
        if (result.empty() || abs(val - result.back()) != 1) {
            perm.erase(perm.begin() + i);
            result.push_back(val);
            solve();
            perm.insert(perm.begin() + i, val);
            result.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    cin >> maxNum;
    if (maxNum == 1) {
        cout << 1 << '\n';
        return 0;
    }
    perm.resize(maxNum);
    iota(perm.rbegin(), perm.rend(), 1);
    solve();
    cout << "NO SOLUTION" << '\n';
}
