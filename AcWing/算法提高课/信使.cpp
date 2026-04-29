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
    vector<pii> g[n + 1];
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    vector<bool> st(n + 1, false);
    vector<int> d(n + 1, 0x3f3f3f3f);
    queue<int> q;
    d[1] = 0;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int x = q.front();
        q.pop();
        st[x] = false;
        for (auto [y, z] : g[x]) {
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!st[y]) {
                    st[y] = true;
                    q.push(y);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, d[i]);
    if (res == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << res << endl;
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
