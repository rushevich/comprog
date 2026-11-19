#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void open_file(string name, bool usaco = false) {
    freopen((name + (usaco ? ".in" : "")).c_str(), "r", stdin);
    freopen((name + (usaco ? ".out" : "")).c_str(), "w", stdout);
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    open_file("milkorder", true);

    int nCows{}, nHierarchy{}, nSpecific{};
    cin >> nCows >> nHierarchy >> nSpecific;

    vector<int> hierarchy(nHierarchy);
    bool cow1_present{false};
    for (auto& h : hierarchy) {
        cin >> h;
        --h;
        cow1_present |= h == 0;
    };

    vector<pair<int, int>> spec_pos(nSpecific);
    for (auto& [cow, pos] : spec_pos) {
        cin >> cow >> pos;
        --cow, --pos; /* number cows from 0 -> N-1 */
    }

    vector<int> cows(nCows, -1);   /* cows[i] = -1 -> no cow here yet */
    vector<int> placed(nCows, -1); /* index of cows placement or -1 if not placed */
    /* Specific positions -> strict constraint */
    for (const auto& [cow, pos] : spec_pos) {
        cows[pos] = cow;
        placed[cow] = pos;
    }

    auto place = [&cows, &placed, &hierarchy, nCows](bool going_right) mutable {
        if (placed[0] != -1) return;
        int i{going_right ? 0 : nCows - 1};
        const int bound{going_right ? nCows : -1};
        const int shift = going_right ? 1 : -1;
        if (going_right) reverse(all(hierarchy));
        int cow{hierarchy.back()};
        for (; i != bound; i += shift) {
            if (placed[cow] != -1) {
                i = placed[cow];
                hierarchy.pop_back();
                if (hierarchy.empty()) break;
                cow = hierarchy.back();
            } else {
                if (cows[i] != -1) continue;
                placed[cow] = i;
                cows[i] = cow;
                hierarchy.pop_back();
                if (hierarchy.empty() || cow == 0) break;
                cow = hierarchy.back();
            }
        }
        if (placed[0] == -1) placed[0] = find(all(cows), -1) - begin(cows);
    };
    place(cow1_present); /* if cow 1 is present, we go right */
    cout << placed[0] + 1 << '\n';
}

void solve() {}
