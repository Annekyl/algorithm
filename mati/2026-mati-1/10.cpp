#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > avg)
            ans++;
    }
    cout << ans << endl;
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