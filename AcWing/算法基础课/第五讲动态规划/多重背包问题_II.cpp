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
constexpr int N = 1e5 + 10;

int n, weigh;
int w[N], v[N], c[N], tot;
int dp[N];

void solve() {
    memset(dp, 0xcf, sizeof dp);

    cin >> n >> weigh;
    FOR(i, 1, n) {
        int x, y, z;
        cin >> x >> y >> z;
        // 二进制拆分
        int p = 1;
        while (p <= z) {
            w[++tot] = x * p;
            v[tot] = y * p;
            z -= p;
            p *= 2;
        }
        if (z > 0) {
            w[++tot] = x * z;
            v[tot] = y * z;
        }
    }

    dp[0] = 0;
    FOR(i, 1, tot) {
        REF(j, weigh, w[i]) { dp[j] = max(dp[j], dp[j - w[i]] + v[i]); }
    }
    int ans = 0;
    FOR(i, 0, weigh) ans = max(ans, dp[i]);
    cout << ans;
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