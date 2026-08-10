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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi a(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (s[i] != s[0])
                a[i] = 1;
        } else {
            if (s[i] != s[i + 1])
                a[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    // cout << ans << endl;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int opl = (l - 1 < 0 ? n - 1 : l - 1);
        int opr = r;
        ans -= a[opl] + a[opr];
        a[opl] = !a[opl];
        a[opr] = !a[opr];
        ans += a[opl] + a[opr];
        // cout << opl << ' ' << opr << ' ' << ans << endl;

        cout << ans << endl;
    }
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
