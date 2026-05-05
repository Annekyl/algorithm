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
constexpr int N = 110;

int n, weigh;
int c[N], w[N][N], v[N][N];
int dp[N];

void solve() {
    memset(dp, 0xcf, sizeof dp);

    cin >> n >> weigh;
    FOR(i, 1, n) {
        cin >> c[i];
        FOR(j, 1, c[i]) { cin >> w[i][j] >> v[i][j]; }
    }

    dp[0] = 0;
    FOR(i, 1, n)
    REF(j, weigh, 0)
    FOR(k, 1, c[i])
    if (w[i][k] <= j)
        dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);

    int ans = 0;
    FOR(i, 0, weigh) ans = max(ans, dp[i]);
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