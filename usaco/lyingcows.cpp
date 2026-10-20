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
    struct info {
        int pos{};
        bool greater{};
    };
    vector<info> infos(N);
    for (int i{}; i < N; ++i) {
        char c{};
        cin >> c >> infos[i].pos;
        infos[i].greater = c == 'G';
    }
    int minLiars{INT_MAX};
    for (auto& curInfo : infos) {
        int liars{};
        int bessie{curInfo.pos};
        for (auto& otherInfo : infos) {
            if (&curInfo == &otherInfo) continue;
            liars += (otherInfo.greater && bessie < otherInfo.pos) || (!otherInfo.greater && bessie > otherInfo.pos);
        }
        minLiars = min(minLiars, liars);
    }
    cout << minLiars << '\n';
}
