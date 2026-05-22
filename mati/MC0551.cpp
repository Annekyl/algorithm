#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][n + 1];
    int b[m + 1][m + 1];
    int s[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    int ans = 0;
    int sz = n - m + 1;
    for (int p = 0; p < 31; p++) {
        // 预处理前缀和
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int val = (a[i][j] >> p) & 1;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + val;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                int r1 = i, c1 = j;
                int r2 = i + sz - 1, c2 = j + sz - 1;

                int cnt1 = s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] +
                           s[r1 - 1][c1 - 1];
                int cnt0 = sz * sz - cnt1;
                int bit = (b[i][j] >> p) & 1;
                if (bit) {
                    cnt = (cnt + cnt0) % mod;
                } else {
                    cnt = (cnt + cnt1) % mod;
                }
            }
        }
        ans = (ans + cnt * (1 << p) % mod) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}