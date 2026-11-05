#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q{};
    cin >> Q;
    map<int, int> mp;
    for (int i{}; i < Q; ++i) {
        int op{};
        cin >> op;
        int key{};
        cin >> key;
        switch (op) {
        case 0: cin >> mp[key]; break;
        case 1: cout << mp[key] << '\n'; break;
        }
    }
}
