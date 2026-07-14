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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int w = a[i];
        // cout << w << endl;
        for (int j = m; j >= w; j--)
                dp[j] += dp[j - w];
    }
    // for (int i = 1; i <= m; i++)
    //     cout << dp[i] << ' ';
    cout << dp[m] << endl;
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
