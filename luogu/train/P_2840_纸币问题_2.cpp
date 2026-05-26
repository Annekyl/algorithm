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
constexpr int mod = 1e9 + 7;
const int N = 1e5 + 10;

void solve() {
    int n, w;
    cin >> n >> w;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(w + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] <= i)
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[w] << endl;
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
