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
const int N = 110;

int n, m;
vi g[N];
int v[N], w[N];
int root;
int dp[N][N];

void dfs(int x) {
    for (int i = v[x]; i <= m; i++) {
        dp[x][i] = w[x];
    }
    for (int y : g[x]) {
        dfs(y);
        for (int i = m; i >= v[x]; i--) {
            for (int j = 0; j <= i - v[x]; j++) {
                dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[y][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            g[p].push_back(i);
    }
    dfs(root);

    cout << dp[root][m] << endl;
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
