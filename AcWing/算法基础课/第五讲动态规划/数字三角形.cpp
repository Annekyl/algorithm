#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 510;

int n;
int a[N][N], tot;
int dp[N][N];

void solve() {
    cin >> n;
    FOR(i, 1, n)
    FOR(j, 1, i)
    cin >> a[i][j];

    memset(dp, 0xcf, sizeof dp);
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        FOR(j, 1, i) {
            dp[i][j] = dp[i - 1][j];
            if (j > 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += a[i][j];
        }
    }
    int ans = dp[n][1];
    FOR(i, 1, n) { ans = max(ans, dp[n][i]); }
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