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
    int N{};
    cin >> N;

    struct Point {
        int x{};
        int y{};
    };

    set<int> xRays; // sorted
    vector<Point> pts(N);
    for (auto& p : pts) {
        cin >> p.x >> p.y;
        xRays.insert(p.x + 1);
    }
    sort(pts.begin(), pts.end(), [](const auto& a, const auto& b) { return a.y < b.y; });
    int M{INT_MAX};
    for (auto a : xRays) {
        array<int, 4> quadrants{};
        // 0 1
        // 2 3
        for (const auto& [x, y] : pts) {
            if (x < a) ++quadrants[0];
            else ++quadrants[1];
        }
        int cowIdx{};
        while (cowIdx < N) {
            int curY{pts[cowIdx].y};
            while (cowIdx < N && pts[cowIdx].y == curY) {
                if (pts[cowIdx].x < a) {
                    --quadrants[0];
                    ++quadrants[2];
                } else {
                    --quadrants[1];
                    ++quadrants[3];
                }
                ++cowIdx;
            }
            M = min(M, *max_element(quadrants.begin(), quadrants.end()));
        }
    }
    cout << M << '\n';
}
