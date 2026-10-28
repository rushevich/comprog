#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

#define USE_FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
#endif
    int nCows{};
    cin >> nCows;

    struct Cow {
        int tArrival{};
        int tQuestioning{};
    };
    vector<Cow> cows(nCows);
    for (auto& c : cows) { cin >> c.tArrival >> c.tQuestioning; }
    sort(all(cows), [](const auto& a, const auto& b) {
        if (a.tArrival == b.tArrival) { return a.tQuestioning < b.tQuestioning; }
        return a.tArrival < b.tArrival;
    });
    // can minimize the totalTime by minimizing the amount of time waited. so at every step, select the cow that arrives
    // the earliest
    int totalTime{};
    for (auto& cow : cows) {
        totalTime = max(totalTime, cow.tArrival);
        totalTime += cow.tQuestioning;
    }
    cout << totalTime << '\n';
}
