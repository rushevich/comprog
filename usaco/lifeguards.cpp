#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
    int N{};
    cin >> N;

    struct Interval {
        int start;
        int end; // exclusive
    };
    array<int, 1001> covg{};
    vector<Interval> guards(N);
    for (int i{}; i < N; ++i) {
        cin >> guards[i].start >> guards[i].end;
        for (int intrvl{guards[i].start}; intrvl < guards[i].end; ++intrvl) { covg[intrvl]++; }
    }
    int totalCovered{};
    for (int i{}; i <= 1000; ++i) {
        if (covg[i] > 0) { ++totalCovered; }
    }
    int minAlone{INT_MAX};
    for (auto [start, end] : guards) {
        int alone{};
        for (; start < end; ++start) {
            if (covg[start] == 1) { ++alone; }
        }
        minAlone = min(alone, minAlone);
    }
    cout << (totalCovered - minAlone) << '\n';
}
