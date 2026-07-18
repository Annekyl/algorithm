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
constexpr int mod = 1e9 + 7;
const int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vi dp(m + 1, -1);
    vi cnt(m + 1, 0);
    dp[0] = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            if (dp[j - v] == -1)
                continue;
            int val = dp[j - v] + w;
            if (val > dp[j]) {
                dp[j] = val;
                cnt[j] = cnt[j - v];
            } else if (val == dp[j]) {
                cnt[j] = (cnt[j] + cnt[j - v]) % mod;
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= m; i++)
        mx = max(mx, dp[i]);
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (dp[i] == mx)
            ans = (ans + cnt[i]) % mod;
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
