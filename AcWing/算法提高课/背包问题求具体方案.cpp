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
    int n, m;
    cin >> n >> m;
    vii dp(n + 2, vi(m + 2, 0)); // 从第i个物品到第n个物品选，容量为j的最大价值
    int v[n + 2], w[n + 2];
    for (int k = 1; k <= n; k++) {
        cin >> v[k] >> w[k];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i]) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    int cur = m;
    for (int i = 1; i <= n; i++) {
        if (cur >= v[i] && dp[i][cur] == dp[i + 1][cur - v[i]] + w[i]) {
            cout << i << ' ';
            cur -= v[i];
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
