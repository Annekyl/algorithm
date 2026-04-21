#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    // cin >> n;
    // cout << atan(666 / 233.0) << endl;
    // cout << sqrt(233 * 233 + 666 * 666) << endl;
    double jiaodu = atan(666 / 233.0);
    double r = sqrt(233 * 233 + 666 * 666);
    double ans = (jiaodu + 1) * r;
    cout << round(ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}