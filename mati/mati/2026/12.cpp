#include "bits/stdc++.h"
#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = k; i <= n; i += k) {
        ans += a[i];
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}