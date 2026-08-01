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
    int n;
    cin >> n;
    int a[2 * n + 1];
    int s[2 * n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    s[0] = 0;
    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + a[i];

    int mn[2 * n + 1][2 * n + 1];
    int mx[2 * n + 1][2 * n + 1];
    memset(mx, -0x3f, sizeof mx);
    memset(mn, 0x3f, sizeof mn);
    for (int i = 0; i <= 2 * n; i++) {
        mn[i][i] = 0;
        mx[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            int cost = s[j] - s[i - 1];
            for (int k = i; k < j; k++) {
                mn[i][j] = min(mn[i][j], mn[i][k] + mn[k + 1][j] + cost);
                mx[i][j] = max(mx[i][j], mx[i][k] + mx[k + 1][j] + cost);
            }
        }
    }

    int mn_ans = INF, mx_ans = -INF;
    for (int i = 1; i <= n; i++) {
        mn_ans = min(mn_ans, mn[i][i + n - 1]);
        mx_ans = max(mx_ans, mx[i][i + n - 1]);
    }
    cout << mn_ans << endl << mx_ans << endl;
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
