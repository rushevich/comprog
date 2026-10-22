#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int T{};
    cin >> T;
    for (int i{}; i < T; ++i) {
        int N{}; // number of log entries
        cin >> N;
        vector<int> log(N);
        int totalHours{};
        for (int j{}; j < N; ++j) {
            cin >> log[j];
            totalHours += log[j];
        }
        if (totalHours == 0) {
            cout << 0 << '\n';
            continue;
        }

        const auto validTarget = [&log](int target) -> bool {
            int sum{};
            for (auto l : log) {
                sum += l;
                if (sum > target) return false;
                else if (sum == target) { sum = 0; }
            }
            return true;
        };
        int minFactor{INT_MAX};
        for (int firstFactor{1}; firstFactor * firstFactor <= totalHours; ++firstFactor) {
            if (totalHours % firstFactor == 0) {
                const int secondFactor = totalHours / firstFactor;
                if (validTarget(firstFactor)) {
                    minFactor = min(firstFactor, minFactor);
                    break;
                }
                if (validTarget(secondFactor)) { minFactor = min(secondFactor, minFactor); }
            }
        }
        cout << (N - totalHours / minFactor) << '\n';
    }
    return 0;
}
