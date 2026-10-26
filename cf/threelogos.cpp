#include <bits/stdc++.h>
using namespace std;

struct Dims {
    int height{};
    int width{};
    char letter{};
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
#ifdef USE_FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif

    vector<Dims> logos(3);
    int sideLength{};
    int totalArea{};
    char ch{'A'};
    for (auto& [height, width, letter] : logos) {
        letter = ch++;
        cin >> width >> height;
        sideLength = max({width, height, sideLength});
        totalArea += width * height;
    }
    if (totalArea != sideLength * sideLength) {
        cout << -1 << '\n';
        return 0;
    }
    sort(logos.begin(), logos.end(),
         [](const auto& a, const auto& b) { return max(a.width, a.height) < max(b.width, b.height); });
    if (logos.back().width < logos.back().height) { swap(logos.back().width, logos.back().height); }
    vector<vector<char>> grid(sideLength, vector<char>(sideLength, '#'));
    bool done{};
    for (int mask{}; mask < (1 << 2); ++mask) {
        vector<Dims> curLogos = logos;
        for (int i{0}; i < 2; ++i) {
            if (mask & (1 << i)) swap(curLogos[i].width, curLogos[i].height);
        }
        auto& [h0, w0, l0] = curLogos[2];
        auto& [h1, w1, l1] = curLogos[0];
        auto& [h2, w2, l2] = curLogos[1];
        if (h1 == h2 && h2 == sideLength - h0 && w1 + w2 == sideLength) {
            // First place the top most
            for (int r{}; r < h0; ++r) {
                for (int c{}; c < w0; ++c) { grid[r][c] = l0; }
            }
            // Then place the second one, in the bottom left
            for (int r{h0}; r < sideLength; ++r) {
                for (int c{}; c < w1; ++c) { grid[r][c] = l1; }
            }

            // Then place the third alongside it
            for (int r{h0}; r < sideLength; ++r) {
                for (int c{w1}; c < sideLength; ++c) { grid[r][c] = l2; }
            }
            done = true;
            break;
        } else if (w1 == w2 && w2 == sideLength && h1 + h2 == sideLength - h0) {
            for (int r{}; r < h0; ++r) {
                for (int c{}; c < sideLength; ++c) { grid[r][c] = l0; }
            }

            for (int r{h0}; r < h0 + h1; ++r) {
                for (int c{}; c < sideLength; ++c) { grid[r][c] = l1; }
            }
            for (int r{h0 + h1}; r < sideLength; ++r) {
                for (int c{}; c < sideLength; ++c) { grid[r][c] = l2; }
            }
            done = true;
            break;
        }
    }
    if (done) {
        cout << sideLength << '\n';
        for (const auto& row : grid) {
            for (const auto& c : row) { cout << c; }
            cout << '\n';
        }
    } else cout << -1 << '\n';
    return 0;
}
