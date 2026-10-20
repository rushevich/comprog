#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif
    struct Point {
        int x{};
        int y{};
    };
    int N{};
    cin >> N;
    vector<Point> pts(N);
    for (int i{}; i < N; ++i) { cin >> pts[i].x >> pts[i].y; }
    int maxArea{};
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            for (int k{}; k < N; ++k) {
                if (pts[j].y == pts[i].y && pts[j].x == pts[k].x) {
                    maxArea = max(maxArea, abs(pts[j].x - pts[i].x) * abs(pts[j].y - pts[k].y));
                }
            }
        }
    }
    cout << maxArea << '\n';
}
