#include <bits/stdc++.h>
using namespace std;
int main() {
  int start{};
  int end{};
  int tStart{};
  int tEnd{};
  fstream in{"teleport.in"};
  in >> start >> end >> tStart >> tEnd;
  int minDist{min({abs(start - end), abs(start - tStart) + abs(tEnd - end),
                   abs(start - tEnd) + abs(tStart - end)})};
  ofstream out{"teleport.out"};

  out << minDist;
}
