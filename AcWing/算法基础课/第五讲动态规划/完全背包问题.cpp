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
constexpr int N = 1010;

int n, w;
pii a[N];
int dp[N];

void solve() {
    memset(dp, 0xcf, sizeof dp);

    cin >> n >> w;
    FOR(i, 1, n) { cin >> a[i].fi >> a[i].se; }
    sort(a + 1, a + n + 1);

    dp[0] = 0;
    FOR(i, 1, n) {
        int weigh = a[i].fi, val = a[i].se;
        FOR(j, weigh, w) { dp[j] = max(dp[j], dp[j - weigh] + val); }
    }
    int ans = 0;
    FOR(i, 1, w) ans = max(ans, dp[i]);
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