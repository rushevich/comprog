#include <bits/stdc++.h>
using namespace std;

#define GET_IO(s)                                                                                                      \
    ifstream in{string{(s)} + ".in"};                                                                                  \
    ofstream out{string{(s)} + ".out"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GET_IO("measurement");
    array<int, 3> output{7, 7, 7}; // bessie, else, mildred
    map<int, vector<pair<int, int>>> ts;
    int N{};
    in >> N;
    for (int i{}; i < N; ++i) {
        int day;
        string cow;
        char sign{};
        int change{};
        in >> day >> cow >> sign >> change;
        int idx{};
        if (cow == "Bessie") idx = 0;
        else if (cow == "Elsie") idx = 1;
        else idx = 2;
        ts[day].emplace_back(idx, (sign == '+' ? change : -change));
    }
    int result{};
    auto bestCows = [&output] {
        vector<int> cows;
        auto max = *max_element(output.begin(), output.end());
        for (int i{}; i < 3; ++i) {
            if (output[i] == max) cows.push_back(i);
        }
        return cows;
    };
    for (auto& [_, changes] : ts) {
        auto bestBefore = bestCows();
        for (const auto& [cow, change] : changes) { output[cow] += change; }
        if (bestCows() != bestBefore) { ++result; }
    }
    out << result << '\n';
}
