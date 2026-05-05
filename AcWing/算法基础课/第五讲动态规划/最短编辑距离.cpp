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
constexpr int N = 1010;

int n, m;
char a[N], b[N];
int dp[N][N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> m;
    FOR(i, 1, m) cin >> b[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    FOR(i, 1, n) dp[i][0] = i;
    FOR(i, 1, m) dp[0][i] = i;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m];
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