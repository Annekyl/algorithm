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
    int n;
    cin >> n;
    string t;
    cin >> t;
    int m = t.size();
    t = " " + t;
    vi ne(m + 1, 0);
    for (int i = 2, j = 0; i <= m; i++) {
        while (j > 0 && t[i] != t[j + 1])
            j = ne[j];
        if (t[i] == t[j + 1])
            j++;
        ne[i] = j;
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!dp[i][j])
                continue;
            for (char c = 'a'; c <= 'z'; c++) {
                int u = j;
                while (u > 0 && c != t[u + 1])
                    u = ne[u];
                if (c == t[u + 1])
                    u++;
                if (u < m)
                    dp[i + 1][u] = (dp[i + 1][u] + dp[i][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++)
        ans = (ans + dp[n][j]) % mod;
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
