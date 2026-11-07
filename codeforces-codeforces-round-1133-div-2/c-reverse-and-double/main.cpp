include<bits / stdc++.h> using namespace std;

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
    int N{};
    cin >> N;
    vector<int> arr(N);
    for (auto& num : arr) cin >> num;
    int minGap{0};
    for (int i{}; i < N - 1; ++i) { minGap = max(minGap, abs(arr[i] - arr[i + 1])); }

    // 9 9 8 2 4 4 3 5 3
    // when we reverse some segment, the minGap can change based on the
    // following: if there is some pair in the segment that when they are both
    // doubled, now exceeds max gap, since pairs within the segment stay
    // adjacent, or if there is a pair formed by the two endpoints
    // if we are swapping l and r, we have to check every pair within (do this
    // by construction of the window) and also the diffs of arr[r] * 2, arr[l -
    // 1] and arr[l] * 2, arr[r + 1].
    // if we encounter a point where 2 * arr[r] - 2 * arr[r + 1] is greater than
    // the minGap we've seen so far, we should immediately shrink left to right
    // and then continue

    int left{};
    for (int right{1}; right < N; ++right) {
        int thisGap{2 * arr[right] - 2 * arr[right - 1]};
        if (thisGap > minGap) {
            left = right;
            continue;
        }
        while (left < right) {
            if ((left > 0 && abs(2 * arr[right] - arr[left - 1]) > minGap) ||
                (right < N - 1 && abs(2 * arr[left] - arr[right + 1]) > minGap)) {
                ++left;
                continue;
            } else {
                break;
            }
        }
        minGap = (left != right) ? thisGap : minGap;
    }
    cout << minGap << '\n';
}
