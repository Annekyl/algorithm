#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - '0';
        if (x == 1)
            sum = (sum + i) % mod;
        else {
            ans = (ans + sum * (n - i + 1) % mod) % mod;
        }
    }
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