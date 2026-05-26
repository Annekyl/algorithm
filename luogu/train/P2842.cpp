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
    int n, w;
    cin >> n >> w;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int dp[w + 1];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= w; j++) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    cout << dp[w] << endl;
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