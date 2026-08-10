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
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vii> dp(2, vii(30, vi(30, INF)));
    for (int k = 0; k <= 25; k++) {
        dp[0][0][k] = y * k;
    }

    for (int i = 1; i <= n; i++) {
        int cur = i % 2, pre = (i - 1) % 2;
        // 初始化当前层
        for (int j = 0; j <= 25; j++) {
            for (int k = 0; k <= 25; k++) {
                dp[cur][j][k] = INF;
            }
        }

        for (int j = 0; j <= 25; j++) {     // 第i个人的点燃次数
            for (int k = 0; k <= 25; k++) { // 第i+1个人的点燃次数
                if (i == n && k > 0)
                    break;

                int mn = INF;
                for (int w = 0; w <= 25; w++) { // 第i-1个人的点燃次数
                    if (dp[pre][w][j] == INF)
                        continue;
                    int dmg = w + j * 2 + k;
                    int rem = max(0LL, a[i] - dmg);
                    int cost = dp[pre][w][j] + rem * x;
                    mn = min(mn, cost);
                }

                if (mn != INF) {
                    dp[cur][j][k] = mn + (i == n ? 0LL : k * y);
                }
            }
        }
    }

    int ans = INF;
    int last = n % 2;
    for (int j = 0; j <= 25; j++) {
        ans = min(ans, dp[last][j][0]);
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
