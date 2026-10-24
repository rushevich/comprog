#include <bits/stdc++.h>
using namespace std;

#define sci(x) static_cast<int>((x))

void solve(array<int, 26>&, const string&, string&, vector<string>& result);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    string in;
    cin >> in;
    array<int, 26> cFreqs{};
    for (char c : in) { ++cFreqs[c - 'a']; }
    vector<string> result;
    string cur;
    solve(cFreqs, in, cur, result);
    cout << result.size() << '\n';
    for (const auto& s : result) { cout << s << '\n'; }
    return 0;
}

void solve(array<int, 26>& cfreqs, const string& in, string& cur, vector<string>& result) {
    if (cur.size() == in.size()) { result.push_back(cur); }
    for (int i{}; i < 26; ++i) {
        if (cfreqs[i] > 0) {
            cur.push_back('a' + i);
            --cfreqs[i];
            solve(cfreqs, in, cur, result);
            ++cfreqs[i];
            cur.pop_back();
        }
    }
}
