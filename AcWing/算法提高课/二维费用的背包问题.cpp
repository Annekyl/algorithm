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
    int n, V, M;
    cin >> n >> V >> M;
    int dp[V + 1][M + 1] = {0};
    memset(dp, 0, sizeof dp);
    for (int k = 0; k < n; k++) {
        int v, m, w;
        cin >> v >> m >> w;
        for (int i = V; i >= v; i--) {
            for (int j = M; j >= m; j--) {
                dp[i][j] = max(dp[i][j], dp[i - v][j - m] + w);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= M; j++) {
            ans = max(ans, dp[i][j]);
        }
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
