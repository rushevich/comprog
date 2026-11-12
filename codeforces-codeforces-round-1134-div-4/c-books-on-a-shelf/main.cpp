#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin((x)), end((x))
#define sci(x) static_cast<int>((x))

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int numTests{};
    cin >> numTests;
    while (numTests--) { solve(); }
}
void solve() {
    int nBooks{};
    cin >> nBooks;
    vector<ll> books(nBooks);
    ll maxBook{};
    for (auto& b : books) {
        cin >> b;
        maxBook = max(maxBook, b);
    };

    auto sortMountain = [](auto& range) {
        if (size(range) < 3) return vector<ll>(all(range));
        sort(all(range));
        deque<ll> mountain;
        bool placeRight{true};
        for (ll x : range | views::reverse) {
            if (placeRight) {
                mountain.push_back(x);
            } else {
                mountain.push_front(x);
            }
            placeRight = !placeRight;
        }
        return vector<ll>(all(mountain));
    };

    vector<ll> mountain = sortMountain(books);

    int booksVisible{};
    for (int i{0}; i < nBooks; ++i) {
        const ll leftBook{i == 0 ? 0 : mountain[i - 1]};
        const ll rightBook{mountain[i]};
        booksVisible += rightBook > leftBook;
    }
    for (int i{nBooks - 1}; i >= 0; --i) {
        const ll leftBook{mountain[i]};
        const ll rightBook{i == nBooks - 1 ? 0 : mountain[i + 1]};
        booksVisible += leftBook > rightBook;
    }
    booksVisible -= count(all(mountain), maxBook) == 1;
    cout << booksVisible << '\n';
    for (int i{}; ll b : mountain) {
        if (i++ > 0) cout << ' ';
        cout << b;
    }
    cout << '\n';
}
