#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N{};
    ifstream in{"shell.in"};
    ofstream out{"shell.out"};
    in >> N;
    int A{};
    int B{};
    int G{};
    vector<tuple<int, int, int>> rounds;
    for (int i{}; i < N; ++i) {
        in >> A;
        in >> B;
        in >> G;
        rounds.push_back(make_tuple(A, B, G));
    }
    int result{};
    for (int start{1}; start <= 3; ++start) {
        int loc{start};
        int correct{};
        for (auto [a, b, g] : rounds) {
            if (loc == a) {
                loc = b;
            } else if (loc == b) {
                loc = a;
            }
            correct += g == loc;
        }
        result = max(result, correct);
    }
    out << result << '\n';
}
