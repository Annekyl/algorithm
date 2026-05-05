#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 110;

struct Node {
    int v, w, s;
} node[N];

int n, v;
int dp[N];

void solve() {
    memset(dp, 0xcf, sizeof dp);

    cin >> n >> v;
    FOR(i, 1, n) { cin >> node[i].v >> node[i].w >> node[i].s; }

    dp[0] = 0;
    FOR(i, 1, n) {
        FOR(j, 1, node[i].s) {
            REF(k, v, node[i].v) {
                dp[k] = max(dp[k], dp[k - node[i].v] + node[i].w);
            }
        }
    }

    int ans = 0;
    FOR(i, 1, v) ans = max(ans, dp[i]);
    cout << ans << endl;
    // cout << dp[v];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}