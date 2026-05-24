#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m, t1, t2;
    cin >> n >> m >> t1 >> t2;
    int g[n + 1][m + 1] = {0};
    int s[n + 1][m + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            s[i][j] = s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1] ^ g[i][j];
        }
    }

    int ans = 0;
    for (int i = t1; i <= n; i += t1) {
        for (int j = t2; j <= m; j += t2) {
            // cout << i << ' ' << j << ' ';
            int val = s[i][j] ^ s[i - t1][j] ^ s[i][j - t2] ^ s[i - t1][j - t2];
            // cout << val << endl;
            ans += val;
        }
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