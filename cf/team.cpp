#include <bits/stdc++.h>
using namespace std;
int main() {
  int n{};
  std::cin >> n;
  int count{};
  for (; n > 0; --n) {
    int sureCount{};
    for (int i{}; i < 3; ++i) {
      int sure{};
      std::cin >> sure;
      sureCount += sure;
    }
    count += sureCount >= 2;
  }
  std::cout << count << '\n';
}
