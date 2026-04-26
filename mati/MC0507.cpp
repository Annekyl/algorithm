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

int n, m;

void solve() {
    cin >> n >> m;
    int g[n + 1][m + 1];
    int cnt[n + 1][m + 1];
    memset(cnt, 0, sizeof 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            cnt[i][j] =
                cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + g[i][j];
        }
    }
    int ans = 0;
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= m; y2++) {
                    int sz = (x2 - x1 + 1) * (y2 - y1 + 1);
                    int cnt1 = cnt[x2][y2] + cnt[x1 - 1][y1 - 1] -
                               cnt[x2][y1 - 1] - cnt[x1 - 1][y2];
                    // cout << x1 << " " << y1 << " " << x2 << " " << y2 <<
                    // endl; cout << sz << " " << cnt1 << endl;
                    if (cnt1 > sz - cnt1)
                        ans++;
                }
            }
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