#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("pails");
    int X, Y, M;
    in >> X >> Y >> M;
    int maxX = M / X;
    int maxY = M / Y;
    int result{};
    for (int i{}; i <= maxX; ++i) {
        int m{i * X};
        for (int j{}; j <= maxY; ++j) {
            if (m + Y <= M) m += Y;
            else break;
        }
        result = max(m, result);
    }
    out << result << '\n';
}
