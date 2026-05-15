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

// 1:0 1种
// 2:0 1 2种
// 3:0 2 3 3种
// 4:0

void solve() {
    int n;
    cin >> n;
    int mx = n * (n - 1) / 2 + 1;
    int dp[n + 1][mx];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            int point = k * (i - k);
            for (int j = point; j < mx; j++) {
                if (dp[i - k][j - point])
                    dp[i][j] = dp[i - k][j - point];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < mx; i++) {
        ans += dp[n][i];
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
