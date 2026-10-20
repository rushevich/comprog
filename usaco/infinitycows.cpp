#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};
struct point {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N{};
    cin >> N;
    const auto nStops = [](point n, point e) -> int {
        if (e.x > n.x || n.y >= e.y || e.y - n.y <= n.x - e.x) return -1;
        return e.y - n.y;
    };

    const auto eStops = [](point n, point e) -> int {
        if (e.x >= n.x || n.y > e.y || e.y - n.y >= n.x - e.x) return -1;
        return n.x - e.x;
    };

    vector<pair<point, char>> cows(N);
    for (int i{}; i < N; ++i) { cin >> cows[i].second >> cows[i].first.x >> cows[i].first.y; }
    struct StopEvent {
        int distance;       // the distance of the cow that stops
        int movingDistance; // the distance of the cow that continues moving
        int stoppingCow;    // the cow that stops (index into cows)
        int movingCow;      // the cow that keeps on moving
    };
    auto comp = [](const StopEvent& a, const StopEvent& b) { return a.distance < b.distance; };
    vector<StopEvent> events;
    for (int i{}; i < N; ++i) {
        for (int j{i + 1}; j < N; ++j) {
            int I = i;
            int J = j;
            auto nCow = cows[I];
            auto eCow = cows[J];
            if (nCow.second == eCow.second) continue;
            if (nCow.second != 'N') swap(nCow, eCow), swap(I, J);
            int stoppingDistance{};
            const point& n = nCow.first;
            const point& e = eCow.first;
            if ((stoppingDistance = nStops(n, e)) != -1) events.push_back({stoppingDistance, n.x - e.x, I, J});
            else if ((stoppingDistance = eStops(n, e)) != -1) events.push_back({stoppingDistance, e.y - n.y, J, I});
        }
    }
    sort(events.begin(), events.end(), comp);
    unordered_map<int, int> stopped; // cow -> distance moved
    for (const auto& [d, mD, s, m] : events) {
        // we ignore this stop event if:
        // - s is already stopped
        // - the moving cow that causes this stop has already stopped (we check if it is in stopped, if it is, we have
        // to make sure that the tracked stopping distance > the distance that the moving cow has traveled when the
        // current stop occurs)
        if (stopped.count(s)) continue;
        auto it = stopped.find(m);
        if (it != stopped.end() && it->second <= mD) continue;
        stopped[s] = d;
    }
    for (int i{}; i < cows.size(); ++i) {
        auto it = stopped.find(i);
        if (it != stopped.end()) {
            cout << it->second << '\n';
        } else cout << "Infinity\n";
    }
}
