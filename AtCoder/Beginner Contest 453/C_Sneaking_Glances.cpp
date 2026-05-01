#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

int positive(double x, double y) { return x * y < 0; }

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    function<void(double, int, int)> dfs = [&](double pos, int idx,
                                               int cnt) -> void {
        if (idx == n) {
            ans = max(ans, cnt);
            // cout << cnt << ' ' << pos << endl;
            return;
        }

        // 正方向
        dfs(pos + a[idx], idx + 1, cnt + positive(pos, pos + a[idx]));
        dfs(pos - a[idx], idx + 1, cnt + positive(pos, pos - a[idx]));
    };

    dfs(0.5, 0, 0);
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
