#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
#endif
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    struct Event {
        int person{};
        int milk{-1}; // -1 indicates that this is a sick event
        int time{};
    };
    vector<Event> events(D + S);
    for (int i{}; i < D; ++i) {
        auto& ev = events[i];
        cin >> ev.person >> ev.milk >> ev.time;
    }
    for (int i{D}; i < D + S; ++i) {
        auto& ev = events[i];
        cin >> ev.person >> ev.time;
    }
    sort(events.begin(), events.end(),
         [](const auto& a, const auto& b) { return tie(a.time, a.milk) < tie(b.time, b.milk); });

    // Now we have some list of events
    int medicineNeeded{};
    for (int m{1}; m <= M; ++m) {
        vector<int> pDrankM(N + 1);
        bool plausible{true};
        for (const auto& e : events) {
            if (e.milk == -1) {                  // sick event
                if (pDrankM[e.person]) continue; // no contradiction, e is plausibly sick
                plausible = false;
                break;
            } else if (e.milk == m) { // event where m was drunk, means e.p gets sick
                pDrankM[e.person] = 1;
            }
        }
        // Now, pDrankM has the people that could get sick if they drank m, and m was spoiled
        if (plausible) { medicineNeeded = max(medicineNeeded, accumulate(pDrankM.begin(), pDrankM.end(), 0)); }
    }
    cout << medicineNeeded << '\n';
}
