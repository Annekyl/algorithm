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

int mn_s[30], mn_v[30];

void init() {
    for (int i = 1; i <= 20; i++) {
        mn_s[i] = mn_s[i - 1] + 2 * i * i;
        mn_v[i] = mn_v[i - 1] + i * i * i;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    init();

    int ans = INF;
    function<void(int, int, int, int, int)> dfs =
        [&](int depth, int sum_v, int sum_s, int pre_r, int pre_h) {
            if (depth == 0) {
                if (sum_v == n)
                    ans = min(ans, sum_s);
                return;
            }

            if (sum_v + mn_v[depth] > n)
                return;

            if (sum_s + mn_s[depth] >= ans)
                return;

            if (sum_s + 2 * (n - sum_v) / pre_r >= ans)
                return;

            int max_r = min(pre_r - 1, (int)sqrt(n - sum_v));
            for (int r = max_r; r >= depth; r--) {
                // 最底层的上表面积
                int top_s = (depth == m) ? r * r : 0;

                int mx_h = min(pre_h - 1, (n - sum_v) / (r * r));
                for (int h = mx_h; h >= depth; h--) {
                    dfs(depth - 1, sum_v + r * r * h, sum_s + 2 * r * h + top_s,
                        r, h);
                }
            }
        };

    dfs(m, 0, 0, sqrt(n) + 1, n + 1);
    if (ans == INF)
        cout << 0 << endl;
    else
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
