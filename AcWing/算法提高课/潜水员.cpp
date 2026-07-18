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
    int m, n;
    cin >> m >> n;
    int k;
    cin >> k;
    int dp[m + 1][n + 1];
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int q = 0; q < k; q++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                dp[i][j] =
                    min(dp[i][j], dp[max(i - a, 0LL)][max(j - b, 0LL)] + c);
            }
        }
    }
    cout << dp[m][n] << endl;
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
