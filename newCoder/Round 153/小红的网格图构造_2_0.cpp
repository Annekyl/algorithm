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

    // if (n == 1 && m == 1) {
    //     cout << "No" << endl;
    //     return;
    // }

    int mn = (n / 2) * (m / 2);
    int mx = n * m - mn;
    if (k < mn || k > mx) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        vii g(n + 1, vi(m + 1, 0));

        int flag = 0;
        if (k > n * m / 2) {
            flag = 1;
            k = n * m - k;
        }

        // 先填右下角
        for (int i = 2; i <= n; i += 2) {
            for (int j = 2; j <= m; j += 2) {
                if (k) {
                    k--;
                    g[i][j] = 1;
                }
            }
        }
        // if (n >= m) {
        // 同时填右上和左下
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= m; j += 2) {
                if (k && j + 1 <= m) {
                    k--;
                    g[i][j + 1] = 1;
                }
                if (k && i + 1 <= n) {
                    k--;
                    g[i + 1][j] = 1;
                }
            }
        }
        // }
        //  else {
        //     // 同时填左上和右上
        //     for (int i = 1; i <= n; i += 2) {
        //         for (int j = 1; j <= m; j += 2) {
        //             if (k) {
        //                 k--;
        //                 g[i][j] = 1;
        //             }
        //             if (k && j + 1 <= m) {
        //                 k--;
        //                 g[i][j + 1] = 1;
        //             }
        //         }
        //     }
        // }

        // // 左下
        // for (int i = 2; i <= n; i += 2) {
        //     for (int j = 1; j <= m; j += 2) {
        //         if (k) {
        //             k--;
        //             g[i][j] = 1;
        //         }
        //     }
        // }
        // // 左上
        // for (int i = 1; i <= n; i += 2) {
        //     for (int j = 1; j <= m; j += 2) {
        //         if (k) {
        //             k--;
        //             g[i][j] = 1;
        //         }
        //     }
        // }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (g[i][j] ^ flag);
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
