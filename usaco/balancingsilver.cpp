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
    set<int> yRays;
    vector<Point> pts(N);
    for (auto& p : pts) {
        cin >> p.x >> p.y;
        xRays.insert(p.x + 1);
        yRays.insert(p.y + 1);
    }

    int M{INT_MAX};
    for (auto a : xRays) {
        array<int, 4> quadrants{};
        int i{};
        for (auto b : yRays) { array }
    }
    cout << M << '\n';
}
