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
    vi dp(m + 1, 0), pre(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        pre = dp;
        if (s == -1) {
            for (int i = v; i <= m; i++)
                dp[i] = max(dp[i], pre[i - v] + w);
        } else if (s == 0) {
            for (int i = v; i <= m; i++)
                dp[i] = max(dp[i], dp[i - v] + w);
        } else {
            for (int j = 0; j < v; j++) {
                deque<int> q;
                for (int k = j; k <= m; k += v) {
                    while (q.size() && q.front() < k - s * v)
                        q.pop_front();
                    while (q.size() && pre[q.back()] - (q.back() - j) / v * w <=
                                           pre[k] - (k - j) / v * w)
                        q.pop_back();
                    q.push_back(k);
                    dp[k] = pre[q.front()] + (k - q.front()) / v * w;
                }
            }
        }
    }
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