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
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n, l, W;
    cin >> n >> l >> W;
    __int128_t sum1 = 0, sum2 = 0;
    int w[n], x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> w[i];
        sum1 += x[i] * w[i];
        sum2 += w[i];
    }
    sum1 *= 2;
    sum2 *= 2;
    sum1 += W * l;
    sum2 += W * 2;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        __int128_t re1 = sum1 - x[i] * w[i] * 2, re2 = sum2 - w[i] * 2;
        if (re1 % re2 == 0) {
            ans++;
        }
    }
    cout << ans << endl;
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
