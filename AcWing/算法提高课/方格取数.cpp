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
    memset(a, 0, sizeof a);
    int x, y, z;
    while (cin >> x >> y >> z, x) {
        a[x][y] = z;
    }

    int f[n * 2][n + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int k = 1; k <= n * 2; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;

				// ⚠️注意判断不要越界
                if (j1 < 1 || j1 > n || j2 < 1 || j2 > n)
                    continue;
                int t = a[i1][j1];
                if (i1 != i2)
                    t += a[i2][j2];
                int &x = f[k][i1][i2];
                x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                x = max(x, f[k - 1][i1 - 1][i2] + t);
                x = max(x, f[k - 1][i1][i2 - 1] + t);
                x = max(x, f[k - 1][i1][i2] + t);
            }
        }
    }
    cout << f[n * 2][n][n] << endl;
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
