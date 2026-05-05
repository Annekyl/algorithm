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

int n;
int a[N];
int dp[N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    FOR(i, 1, n) {
        FOR(j, 0, i - 1) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }
    int ans = 0;
    FOR(i, 1, n) ans = max(ans, dp[i]);
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