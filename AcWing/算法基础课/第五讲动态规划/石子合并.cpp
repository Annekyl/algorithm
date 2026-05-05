#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 310;

int n;
int a[N], s[N];
int dp[N][N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    // 预处理前缀和
    FOR(i, 1, n) s[i] = s[i - 1] + a[i];

    memset(dp, 0x3f, sizeof dp);
    FOR(i, 1, n) dp[i][i] = 0;
    FOR(len, 2, n) {
        FOR(l, 1, n - len + 1) {
            int r = l + len - 1;
            FOR(k, l, r) {
                dp[l][r] =
                    min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n];
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