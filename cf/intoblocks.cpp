#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rsort(x) ranges::sort((x))
#define sci(x) static_cast<int>((x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int nElements{}, q{};
    cin >> nElements >> q;
    using Block = tuple<int, int, int>; // start, end, size
    map<int, vector<int>> vToIndices;
    for (int i{}; i < nElements; ++i) {
        int v{};
        cin >> v;
        vToIndices[v].push_back(i);
    }
    vector<Block> blocks;
    for (const auto& [_, indices] : vToIndices) {
        blocks.emplace_back(indices.front(), indices.back(), indices.size());
    }
    rsort(blocks);
    auto [curStart, curEnd, curSize] = blocks.front();
    int maxFreq{};
    int difficulty{};
    for (const auto& [start, end, size] : blocks) {
        if (start > curEnd) {
            difficulty += curEnd - curStart + 1 - maxFreq;
            curStart = start;
            curEnd = end;
            maxFreq = size;
        } else {
            curEnd = max(curEnd, end);
            maxFreq = max(maxFreq, size);
        }
    }
    difficulty += curEnd - curStart + 1 - maxFreq;
    cout << difficulty << '\n';
}
