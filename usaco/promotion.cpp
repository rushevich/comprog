#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream in{"promote.in"};
  ofstream out{"promote.out"};
  array<pair<int, int>, 4> stats{};
  int before{};
  int after{};
  for (auto &p : stats) {
    in >> p.first;
    before += p.first;
    in >> p.second;
    after += p.second;
  }
  array<int, 3> promotions{};
  promotions[2] = stats[3].second - stats[3].first;
  for (int i{2}; i > 0; --i) {
    promotions[i - 1] = stats[i].second - stats[i].first + promotions[i];
  }
  for (auto p : promotions) {
    out << p << '\n';
  }
}
