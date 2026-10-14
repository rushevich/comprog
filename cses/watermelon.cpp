#include <iostream>

int main() {
  int n{};
  std::cin >> n;
  if (n % 2 == 0 && n > 2) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}
