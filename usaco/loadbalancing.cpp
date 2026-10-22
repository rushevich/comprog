#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
#endif
    int N{}, B{};
    cin >> N >> B;
    struct Point {
        int x{};
        int y{};
    };
    vector<Point> pts(N);
    set<int> xRays;
    set<int> yRays;
    for (int i{}; i < N; ++i) {
        cin >> pts[i].x >> pts[i].y;
        xRays.insert(pts[i].x + 1);
        yRays.insert(pts[i].y + 1);
    }

    int M{INT_MAX};
    for (auto a : xRays) {
        for (auto b : yRays) {
            array<int, 4> qs{}; // q1 top right, q2 top left, q3 bot left, q4 bot right
            for (const auto& [x, y] : pts) {
                if (x > a && y > b) ++qs[0];
                else if (x < a && y > b) ++qs[1];
                else if (x < a && y < b) ++qs[2];
                else ++qs[3];
            }
            M = min(M, *max_element(qs.begin(), qs.end()));
        }
    }
    cout << M << '\n';
}
