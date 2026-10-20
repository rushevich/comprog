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
    vector<int> flowers(N);
    for (int i{}; i < N; ++i) { cin >> flowers[i]; }

    int count{};
    for (int i{}; i < N; ++i) {
        unordered_set<int> fs;
        int sum{};
        for (int j{i}; j < N; ++j) {
            fs.insert(flowers[j]);
            sum += flowers[j];
            count += (sum % (j - i + 1) == 0 && fs.count(sum / (j - i + 1)) > 0);
        }
    }
    cout << count << '\n';
}
