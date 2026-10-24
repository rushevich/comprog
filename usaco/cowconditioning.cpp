#include <bits/stdc++.h>
using namespace std;
struct Cow {
    int start{};
    int end{};
    int coolingReq{};
};
struct AC {
    int start{};
    int end{};
    int cooling{};
    int cost{};
};

int minCost{INT_MAX};
vector<Cow> cows;
vector<AC> acs;
vector<bool> acUsed;
int nCows{}, nAC{};

bool cowsCooled(const auto& covg) {
    for (const auto& c : cows) {
        for (int i{c.start}; i <= c.end; ++i) {
            if (covg[i] < c.coolingReq) return false;
        }
    }
    return true;
}
void applyAC(int ac, auto& covg) {
    const auto& [s, e, c, _] = acs[ac];
    for (int i{s}; i <= e; ++i) { covg[i] += c; }
}

void solve() {
    for (int mask{}; mask < (1 << nAC); ++mask) {
        int cost{};
        array<int, 101> covg{};
        for (int i{}; i < nAC; ++i) {
            if (mask & (1 << i)) { // add to the cost, apply ac
                cost += acs[i].cost;
                applyAC(i, covg);
            }
        }
        if (cowsCooled(covg)) { minCost = min(minCost, cost); }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    cin >> nCows >> nAC;
    cows.resize(nCows);
    acs.resize(nAC);
    acUsed.resize(nAC);
    for (auto& c : cows) { cin >> c.start >> c.end >> c.coolingReq; }
    for (auto& a : acs) { cin >> a.start >> a.end >> a.cooling >> a.cost; }
    solve();
    cout << minCost << '\n';
}
