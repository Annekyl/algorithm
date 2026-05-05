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

int n, v;
pii a[N];
// int dp[N][N];
int dp[N];

void solve() {
    memset(dp, 0, sizeof dp);

    cin >> n >> v;
    FOR(i, 1, n) {
        int v, w;
        cin >> v >> w;
        a[i] = {v, w};
    }
    sort(a + 1, a + n + 1);

    // FOR(i, 1, n) {
    //     int w = a[i].fi;
    //     int val = a[i].se;
    //     FOR(j, 1, v) {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j - w >= 0) {
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + val);
    //         }
    //     }
    // }
    // cout << dp[n][v];

    FOR(i, 1, n) {
        int w = a[i].first;
        int val = a[i].second;
        REF(j, v, w) { dp[j] = max(dp[j], dp[j - w] + val); }
    }
    cout << dp[v];
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