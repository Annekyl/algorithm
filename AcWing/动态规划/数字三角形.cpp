#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    int f[n + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j > 1 && j < i)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]);
            else if (j == 1)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j - 1];
            f[i][j] += a[i][j];
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    int ans = -(1 << 30);
    for (int i = 1; i <= n; i++) {
        // debug(f[n][i]);
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
