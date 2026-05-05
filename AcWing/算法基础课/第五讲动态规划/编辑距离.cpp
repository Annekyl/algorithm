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
char a[N][15];
int dp[15][15];

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> (a[i] + 1);

    while (m--) {
        char s[15];
        int k;
        cin >> s + 1 >> k;
        int l1 = strlen(s + 1);

        int ans = 0;

        FOR(t, 1, n) {
            int l2 = strlen(a[t] + 1);

            memset(dp, 0x3f, sizeof dp);
            dp[0][0] = 0;
            FOR(i, 1, l1) dp[i][0] = i;
            FOR(i, 1, l2) dp[0][i] = i;

            FOR(i, 1, l1) {
                FOR(j, 1, l2) {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    if (s[i] == a[t][j])
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            // cout << k << " ";
            // cout << dp[l1][l2] << endl;
            if (dp[l1][l2] <= k)
                ans++;
        }
        cout << ans << endl;
    }
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