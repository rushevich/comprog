#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  struct point {
    int x;
    int y;
  };
  ifstream in{"buckets.in"};
  ofstream out{"buckets.out"};
  point B;
  point R;
  point L;
  for (int r{}; r < 10; ++r) {
    for (int c{}; c < 10; ++c) {
      char ch{};
      in >> ch;
      switch (ch) {
      case 'B':
        B = point{.x = r, .y = c};
        break;
      case 'R':
        R = point{.x = r, .y = c};
        break;
      case 'L':
        L = point{.x = r, .y = c};
        break;
      }
    }
  }
  int result = abs(B.x - L.x) + abs(B.y - L.y) - 1;
  int minX = min(B.x, L.x);
  int maxX = max(B.x, L.x);
  int minY = min(B.y, L.y);
  int maxY = max(B.y, L.y);
  bool impedes = (B.x == L.x && R.x == B.x && R.y > minY && R.y < maxY) ||
                 (B.y == L.y && R.y == B.y && R.x > minX && R.x < maxX);
  result += 2 * impedes;
  out << result << '\n';
  return 0;
}
