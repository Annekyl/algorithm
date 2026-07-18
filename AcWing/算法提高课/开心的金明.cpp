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
    vi dp(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int v, p;
        cin >> v >> p;
        for (int i = n; i >= v; i--) {
            dp[i] = max(dp[i], dp[i - v] + v * p);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[i]);
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
