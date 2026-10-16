#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("mowing");

    int N{};
    in >> N;
    int result{INT_MAX};
    int t{};
    pair<int, int> current;
    std::map<pair<int, int>, int> visited; // pos -> last time visited
    visited[{0, 0}] = 0;
    for (int i{}; i < N; ++i) {
        char dir{};
        int d{};
        in >> dir >> d;
        for (int j{}; j < d; ++j) {
            t++;
            switch (dir) {
            case 'N': current.second++; break;
            case 'E': current.first++; break;
            case 'S': current.second--; break;
            case 'W': current.first--; break;
            }
            auto it = visited.find(current);
            if (it != visited.end()) { result = min(result, t - it->second); }
            visited[current] = t;
        }
    }
    out << (result != INT_MAX ? result : -1) << '\n';
}
