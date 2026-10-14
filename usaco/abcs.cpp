#include <bits/stdc++.h>
using namespace std;
int main() {
  multiset<int> nums;
  for (int i{}; i < 7; ++i) {
    int x{};
    cin >> x;
    nums.insert(x);
  }
  int a{*nums.begin()};
  int b{*next(nums.begin())};
  int c{*prev(nums.end()) - a - b};
  cout << a << ' ' << b << ' ' << c << '\n';
  return 0;
}
