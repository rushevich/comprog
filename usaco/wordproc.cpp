#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N{};
  int K{};
  ifstream in{"word.in"};
  ofstream out{"word.out"};
  in >> N >> K;
  int currentChars{};
  for (; N > 0; --N) {
    string s;
    in >> s;
    if (s.size() + currentChars > K) {
      out << '\n' << s;
      currentChars = s.size();
    } else {
      if (currentChars != 0) {
        out << ' ';
      }
      out << s;
      currentChars += s.size();
    }
  }
  out << '\n';
  return 0;
}
