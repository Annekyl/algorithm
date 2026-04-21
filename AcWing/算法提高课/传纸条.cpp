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

int m, n;

void solve() {
    cin >> m >> n;
    int a[m + 1][n + 1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int f[m + n + 1][m + 1][m + 1];
    memset(f, 0, sizeof f);
    for (int k = 2; k <= m + n; k++) {
        for (int i1 = 1; i1 <= m; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 < 1 || j1 > n || j2 < 1 || j2 > n)
                    continue;
                if (i1 == i2) {	// ⚠️此时两条路径走到同一个点
                    if (i1 != m || j1 != n)	// ⚠️如果这个点不是最后的终点，就要跳过
                        continue;
                }
                int &x = f[k][i1][i2];
                int t = a[i1][j1] + a[i2][j2];
                x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                x = max(x, f[k - 1][i1 - 1][i2] + t);
                x = max(x, f[k - 1][i1][i2 - 1] + t);
                x = max(x, f[k - 1][i1][i2] + t);
                // cout << k << " " << i1 << " " << i2 << " ";
                // debug(x);
            }
        }
    }
    cout << f[m + n][m][m] << endl;
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
