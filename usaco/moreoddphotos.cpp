#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int nPhotos{};
    cin >> nPhotos;
    int nOdd{};
    int nEven{};
    for (int i{}; i < nPhotos; ++i) {
        int num{};
        cin >> num;
        nOdd += num % 2 != 0;
        nEven += num % 2 == 0;
    }
    while (nOdd > nEven) {
        nOdd -= 2;
        ++nEven;
    }
    if (nEven > nOdd + 1) { nEven = nOdd + 1; }
    cout << nEven + nOdd << '\n';
}
