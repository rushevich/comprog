#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
#endif
    int cowN{}, T{};
    cin >> cowN >> T;
    vector<bool> finalSick(cowN + 1); // sick[i] = cow i is sick
    for (int i{1}; i <= cowN; ++i) {
        char ch{};
        cin >> ch;
        if (ch == '1') finalSick[i] = true;
    }
    struct Event {
        int t{}; // time of event
        int x{}; // cows x and y that shook hooves
        int y{};
    };
    vector<Event> events(T);
    vector<int> shakeFreq(cowN + 1);
    int M{}; // max shakes done by any cow
    for (auto& e : events) {
        cin >> e.t >> e.x >> e.y;
        M = max({M, ++shakeFreq[e.x], ++shakeFreq[e.y]});
    }
    sort(events.begin(), events.end(), [](const auto& a, const auto& b) { return a.t < b.t; });
    // Test all patient zeros and all
    int lowK{INT_MAX};
    int highK{};                    // we will set this to -1 if upper bound is infinity
    vector<bool> validPZ(cowN + 1); // validPZ[i] = true -> cow i can be a patient-zero

    for (int pZ{1}; pZ <= cowN; ++pZ) {
        // pZ = patientZero
        for (int k{}; k <= M; ++k) {
            vector<bool> isSick(cowN + 1);
            isSick[pZ] = true;
            if (k == 0) {
                validPZ[pZ] = isSick == finalSick;
                if (validPZ[pZ]) lowK = 0;
                continue;
            }
            vector<int> shakesLeft(cowN + 1);
            shakesLeft[pZ] = k;
            for (const Event& e : events) {
                bool xSpreads = isSick[e.x] && shakesLeft[e.x] > 0;
                bool ySpreads = isSick[e.y] && shakesLeft[e.y] > 0;
                bool xWasSick = isSick[e.x];
                bool yWasSick = isSick[e.y];

                if (xSpreads) --shakesLeft[e.x];
                if (ySpreads) --shakesLeft[e.y];
                if (xSpreads && !yWasSick) {
                    isSick[e.y] = true;
                    shakesLeft[e.y] = k;
                }
                if (ySpreads && !xWasSick) {
                    isSick[e.x] = true;
                    shakesLeft[e.x] = k;
                }
            }
            if (isSick == finalSick) {
                validPZ[pZ] = true;
                lowK = min(lowK, k);
                highK = max(highK, k);
            }
        }
    }
    int pZCount = accumulate(validPZ.begin(), validPZ.end(), 0);
    cout << pZCount << ' ' << lowK << ' ';
    if (highK == M) cout << "Infinity\n";
    else cout << highK << '\n';
}
