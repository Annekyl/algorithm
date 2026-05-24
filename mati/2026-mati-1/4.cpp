#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int mn1 = INF, mn2 = INF;
        bool suc = false;
        for (int i = l; i <= r; i++) {
            if (a[i] <= mn1)
                mn1 = a[i];
            else if (a[i] <= mn2)
                mn2 = a[i];
            else {
                suc = true;
            }
        }
        if (suc)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}