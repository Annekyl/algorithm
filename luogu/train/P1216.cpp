#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    int dp[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            dp[j] = max(dp[j - 1], dp[j]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}