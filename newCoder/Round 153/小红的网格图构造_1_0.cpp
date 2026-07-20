#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 1) {
        int mx = (m + 1) / 2;
        if (k > mx) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int j = 1; j <= m; j++) {
                if (k && (j & 1)) {
                    cout << 1;
                    k--;
                } else
                    cout << 0;
            }
        }
        return;
    }

    if (m == 1) {
        int mx = (n + 1) / 2;
        if (k > mx) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; i++) {
                if (k && (i & 1)) {
                    cout << 1 << endl;
                    k--;
                } else
                    cout << 0 << endl;
            }
        }
        return;
    }

    // 2*2及以上，至少要有1个连通块
    if (k == 0) {
        cout << "No" << endl;
        return;
    }

    int mx = ((n + 1) / 2) * ((m + 1) / 2) + (n / 2) * (m / 2);
    if (k > mx) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        vii g(n + 1, vi(m + 1, 0));
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= m; j += 2) {
                g[i][j] = 1;
            }
        }
        int base = ((n + 1) / 2) * ((m + 1) / 2);
        if (k > base) {
            // cout << "----" << endl;
            k -= base;
            // 添加连通块，在偶数行偶数列放1
            for (int i = 2; i <= n; i += 2) {
                for (int j = 2; j <= m; j += 2) {
                    if (k) {
                        g[i][j] = 1;
                        k--;
                    }
                }
            }
        } else if (k < base) {
            k = base - k;
            // 减少连通块
            // 先在偶数行奇数列放1
            for (int i = 2; i <= n; i += 2) {
                if (i == n)
                    continue;
                for (int j = 1; j <= m; j += 2) {
                    if (k) {
                        g[i][j] = 1;
                        k--;
                    }
                }
            }
            // 再在奇数行偶数列放1, m为偶数时j!=m
            for (int i = 1; i <= n; i += 2) {
                for (int j = 2; j <= m; j += 2) {
                    if (j == m)
                        continue;
                    if (k) {
                        g[i][j] = 1;
                        k--;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
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
