#include "bits/stdc++.h"
#define int long long

using namespace std;

void solve() {
    int x;
    cin >> x;
    if (x < 3) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    if (x & 1) {
        cout << x << " " << x * x / 2 << " " << x * x / 2 + 1 << endl;
    } else {
        if (x % 4 == 0) {
            int d = x / 4;
            cout << 3 * d << ' ' << 4 * d << ' ' << 5 * d << endl;
        } else {
            x /= 2;
            cout << 2 * x << " " << 2 * (x * x / 2) << " "
                 << 2 * (x * x / 2 + 1) << endl;
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}