#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N{};
    cin >> N;
    struct point {
        int x;
        int y;
    };
    vector<point> pts(N);
    for (int i{}; i < N; ++i) { cin >> pts[i].x; }
    for (int i{}; i < N; ++i) { cin >> pts[i].y; }
    int result{};

    for (int i{}; i < N; ++i) {
        for (int j{i + 1}; j < N; ++j) {
            int nx = pts[j].x - pts[i].x;
            int ny = pts[j].y - pts[i].y;
            result = max(result, nx * nx + ny * ny);
        }
    }
    cout << result << '\n';
}
