#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int qmi(int a, int b, int p) {
    int res = 1;

    a %= p;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, d;
    cin >> n >> d;
    int dp[n + 1];
    int s[n + 1] = {0};

    if (d == 1) {
        int ans = qmi(4, n, mod);
        cout << ans << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;

        if (i - d > 0)
            dp[i] = (dp[i] + s[i - d]) % mod;
        if (i - d + 1 > 0)
            dp[i] = (dp[i] + s[i - d + 1]) % mod;

        s[i] = (s[i - 1] + dp[i]) % mod;
    }
    int ans = (2 * s[n] + 1) % mod;
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