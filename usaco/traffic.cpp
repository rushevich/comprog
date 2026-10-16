#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in{"traffic.in"};
    ofstream out{"traffic.out"};

    // range is inclusive []
    int N{};
    in >> N;
    enum class ramp { on, off, none };
    struct sensor {
        ramp r;
        int low;
        int high;
    };
    vector<sensor> arr(N + 1);
    int r2Low{-10'000};
    int r2High{10'000};
    for (int i{1}; i <= N; ++i) {
        sensor s;
        string str;
        in >> str >> s.low >> s.high;
        if (str == "on") {
            s.r = ramp::on;
            r2Low += s.low;
            r2High += s.high;
        } else if (str == "off") {
            s.r = ramp::off;
            r2Low -= s.high;
            r2High -= s.low;
        } else {
            s.r = ramp::none;
            r2Low = max(r2Low, s.low);
            r2High = min(r2High, s.high);
        }

        arr[i] = s;
    }

    int r1Low{-10'000};
    int r1High{10'000};
    for (int i{N}; i >= 1; --i) {
        auto& s = arr[i];
        if (s.r == ramp::on) {
            r1Low -= s.high;
            r1High -= s.low;
        } else if (s.r == ramp::off) {
            r1Low += s.low;
            r1High += s.high;
        } else {
            r1Low = max(r1Low, s.low);
            r1High = min(r1High, s.high);
        }
    }
    out << max(0, r1Low) << ' ' << r1High << '\n';
    out << max(0, r2Low) << ' ' << r2High << '\n';

    return 0;
}
