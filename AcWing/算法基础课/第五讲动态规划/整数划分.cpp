#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int N = 1010;

int n;

void solve() {
    cin >> n;

    /*
    // 转化为完全背包问题 f[i][j] = f[i-1][j] + f[i-1][j-i]
    // 一维状态转移方程：f[j] = f[j] + f[j-i]
    int dp[n + 1];
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    FOR(i, 1, n) {
        FOR(j, i, n) { dp[j] = (dp[j] + dp[j - i]) % mod; }
    }

    cout << dp[n];
    */

    // 分为最小值为1或最小值不为1 f[i-1][j-1] 和 f[i-j][j]
    int f[n + 1][n + 1];
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    FOR(i, 1, n) {
        FOR(j, 1, i) { f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod; }
    }

    int ans = 0;
    FOR(i, 1, n) ans = (ans + f[n][i]) % mod;
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}