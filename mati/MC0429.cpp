#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dp[n] = {0};
    for (int i = n - 1; i >= 0; i--) {
        int pre_val = 0; // dp[i+1][j-1]
        dp[i] = 1;
        for (int j = i + 1; j < n; j++) {
            int temp = dp[j]; // dp[i+1][j]
            if (s[i] == s[j]) {
                dp[j] = (dp[j] + dp[j - 1] + 1) % mod;
            } else {
                dp[j] = (dp[j] + dp[j - 1] - pre_val + mod) % mod;  // ⚠️注意+mod防止减法变为负数
            }
            pre_val = temp;
        }
    }
    cout << dp[n - 1] << endl;
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