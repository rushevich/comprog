#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("censor");
    string S, T;
    in >> S >> T;
    string result;
    result.reserve(S.size());
    const int tLen = T.size();
    auto tailMatch = [&T, tLen](const string& str) {
        const int n = str.size();
        if (n < tLen) return false;
        int start = n - tLen;
        for (int i{}; i < tLen; ++i) {
            if (str[start + i] != T[i]) { return false; }
        }
        return true;
    };
    for (auto ch : S) {
        result.push_back(ch);
        if (result.back() == T.back() && tailMatch(result)) { result.resize(result.size() - tLen); }
    }
    out << result << '\n';
}
