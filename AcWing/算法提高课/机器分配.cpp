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
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> path(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                if (dp[i][j] < dp[i - 1][j - k] + v[i][k]) {
                    dp[i][j] = dp[i - 1][j - k] + v[i][k];
                    path[i][j] = k;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    vi ans(n+1);
    int cur = m;
    for (int i = n; i >= 1; i--) {
        ans[i] = path[i][cur];
        cur -= ans[i];
    }
    for (int i = 1; i <= n; i++)
        cout << i << ' ' << ans[i] << endl;
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
