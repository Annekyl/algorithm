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
constexpr int mod = 1e8;
const int N = 15;

vi state;
int g[N];
int dp[N][5000];

void solve() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1)
                g[i] |= (1 << j);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        if (!(i & (i >> 1))) {
            state.push_back(i);
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int a : state) {
            if ((a & g[i]) == a) {
                for (int b : state) {
                    if ((a & b) == 0) {
                        dp[i][a] = (dp[i][a] + dp[i - 1][b]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int a : state) {
        ans = (ans + dp[m][a]) % mod;
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
