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
const int N = 1100;

vi state;
vi cnt;
vi g[N];
int dp[12][105][1000];

int count(int x) {
    int res = 0;
    while (x) {
        res++;
        x -= x & -x;
    }
    return res;
}

bool check(int x, int y) {
    if (x & y)
        return false;
    if (x & (y >> 1))
        return false;
    if (x & (y << 1))
        return false;
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < (1 << n); i++) {
        if (!(i & (i >> 1))) {
            state.push_back(i);
            cnt.push_back(count(i));
        }
    }
    int m = state.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (check(state[i], state[j])) {
                g[i].push_back(j);
            }
        }
    }

    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= k; j++) {
            for (int a = 0; a < m; a++) {
                int c = cnt[a];
                if (j >= c) {
                    for (int b : g[a]) {
                        dp[i][j][a] += dp[i - 1][j - c][b];
                    }
                }
            }
        }
    }
    cout << dp[n + 1][k][0] << endl;
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
