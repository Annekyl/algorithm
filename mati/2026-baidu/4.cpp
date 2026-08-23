#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vi> a(n + 1, vi(n + 1, 0));
    vector<vi> s(n + 1, vi(n + 1, 0));
    vector<vi> g(n + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> g[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            g[i][j] = s[i][j - 1] - s[i][i - 1] + s[j][n] - s[i][n] -
                      s[j][j - 1] + s[i][j - 1];
            // cout << g[i][j] << ' ';
        }
        // cout << endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        ans += g[i][i + 1];
    }
    // cout << ans << endl;
    int add = g[1][n];
    for (int i = 2; i < n; i += 2) {
        add += g[i][i + 1];
    }
    ans = min(ans, add);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}