#include <bits/stdc++.h>
using namespace std;

#define FILE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
#endif
    int N{};
    int K{};
    cin >> N >> K;
    using ImageRow = vector<int>;
    using Image = vector<ImageRow>;
    Image originalFigure(N, ImageRow(N)); // N by N
    for (auto& r : originalFigure) {
        for (auto& c : r) {
            char ch{};
            cin >> ch;
            if (ch == '.') c = 0;
            else c = 1;
        }
    }

    vector<Image> pieces;
    for (int i{}; i < K; ++i) {
        Image currentFigure(N, ImageRow(N));
        for (auto& r : currentFigure) {
            for (auto& c : r) {
                char ch{};
                cin >> ch;
                if (ch == '.') c = 0;
                else c = 1;
            }
        }
        pieces.push_back(move(currentFigure));
    }

    struct Ranges {
        pair<int, int> dc;
        pair<int, int> dr;
    };
    auto findRanges = [N](const Image& img) -> Ranges {
        int highest{INT_MAX};
        int lowest{};
        int leftmost{INT_MAX};
        int rightmost{};
        for (int r{}; r < N; ++r) {
            for (int c{}; c < N; ++c) {
                if (img[r][c] == 1) {
                    highest = min(highest, r);
                    lowest = max(lowest, r);
                    leftmost = min(leftmost, c);
                    rightmost = max(rightmost, c);
                }
            }
        }
        return {{-leftmost, N - 1 - rightmost}, {-highest, N - 1 - lowest}};
    };

    for (int i{}; i < K; ++i) {
        for (int j{i + 1}; j < K; ++j) {
            auto& imgI = pieces[i];
            auto& imgJ = pieces[j];
            auto [iDC, iDR] = findRanges(pieces[i]);
            auto [jDC, jDR] = findRanges(pieces[j]);
            for (int iC{iDC.first}; iC <= iDC.second; ++iC) {
                for (int iR{iDR.first}; iR <= iDR.second; ++iR) {
                    for (int jC{jDC.first}; jC <= jDC.second; ++jC) {
                        for (int jR{jDR.first}; jR <= jDR.second; ++jR) {
                            bool good{true};
                            for (int r{}; r < N; ++r) {
                                for (int c{}; c < N; ++c) {
                                    int reconstructed{};
                                    if ((r - iR >= 0 && r - iR < N) && (c - iC >= 0 && c - iC < N)) {
                                        reconstructed += imgI[r - iR][c - iC];
                                    }
                                    if ((r - jR >= 0 && r - jR < N) && (c - jC >= 0 && c - jC < N)) {
                                        reconstructed += imgJ[r - jR][c - jC];
                                    }
                                    if (reconstructed != originalFigure[r][c]) {
                                        good = false;
                                        break;
                                    }
                                }
                            }
                            if (good) {
                                cout << (i + 1) << ' ' << (j + 1) << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
