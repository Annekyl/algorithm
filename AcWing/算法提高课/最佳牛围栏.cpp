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

int n, f;
double a[N], s[N], mx = 0.0;

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i] - x;
    }
    double mn_pre = 0;
    for (int i = f; i <= n; i++) {
        mn_pre = min(mn_pre, s[i - f]);
        if (s[i] - mn_pre >= 0)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    double l = 0, r = mx;
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = r * 1000;
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
