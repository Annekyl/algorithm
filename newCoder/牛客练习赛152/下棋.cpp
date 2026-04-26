#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int g[n + 1][m + 1];
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = (i + j) & 1;
            if (g[i][j])
                cnt1++;
        }
        // cout << endl;
    }
    bool out = false;
    if (n * m - cnt1 > cnt1)
        out = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (!out ? g[i][j] : !g[i][j]);
        }
        cout << endl;
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
