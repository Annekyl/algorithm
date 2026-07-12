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
    int n;
    cin >> n;
    int val[n + 1], len[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++)
        cin >> len[i];
    int dp[n + 1][2];
    dp[1][1] = max(0LL, len[1] / 2 * val[1]);
    dp[1][0] = max(0LL, (len[1] + 1) / 2 * val[1]);
    for (int i = 2; i <= n; i++) {
        int l = len[i], v = val[i];
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][0] + l / 2 * v,
                        dp[i - 1][1] + (l + 1) / 2 * v});
        dp[i][1] =
            max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][0] + (l - 1) / 2 * v,
                 dp[i - 1][1] + l / 2 * v});
    }
    int ans = max(dp[n][0], dp[n][1]);
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
