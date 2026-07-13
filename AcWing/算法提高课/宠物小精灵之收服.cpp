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
    int n, m, k;
    cin >> n >> m >> k;
    int w1[k], w2[k];
    for (int i = 0; i < k; i++)
        cin >> w1[i] >> w2[i];

    int dp[n + 1][m + 1] = {0};
    for (int i = 0; i < k; i++) {
        for (int j = n; j >= w1[i]; j--) {
            for (int p = m - 1; p >= w2[i]; p--) {
                dp[j][p] = max(dp[j][p], dp[j - w1[i]][p - w2[i]] + 1);
            }
        }
    }
    int mx = dp[n][m - 1];
    // cout<<mx<<endl;
    // return;
    int remain;
    for (remain = 0; remain < m; remain++) {
        if (dp[n][remain] == mx)
            break;
    }
    cout << mx << ' ' << m - remain << endl;
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
