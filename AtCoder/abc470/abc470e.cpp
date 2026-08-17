#include "bits/stdc++.h"
// #include <bits/extc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// typedef tree<int, int, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_map;

// typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

typedef pair<int, int> pii;
typedef vector<double> vi;
typedef vector<vector<double>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 210;

void solve() {
    int n, l;
    cin >> n >> l;
    vi a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<vii> dp(N, vii(N, vi(N, 0)));
    for (int i = 1; i <= l; i++) {
        for (int k = 0; k <= n; k++) {
            dp[i][0][k] = k;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= n - j; k++) {
                double u = 2 * j + k;
                double c0 = j, c1 = k;
                if (k >= 1)
                    dp[i][j][k] += c1 / u * (dp[i][j][k - 1] + 1);
                if (j >= 2)
                    dp[i][j][k] += c0 * 2 / u * 2 * (c0 - 1) / (u - 1) *
                                   dp[i - 1][j - 2][k + 2];
                dp[i][j][k] += c0 * 2 / u / (u - 1) * (dp[i][j - 1][k] + 1);
                if (i > 1) // 有血量时才能拿走
                    dp[i][j][k] +=
                        c0 * 2 / u * c1 / (u - 1) * (dp[i - 1][j - 1][k] + 1);
            }
        }
    }
    double ans = 1.0 * sum / n * dp[l][n][0];
    cout << fixed << setprecision(8) << ans << endl;
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
