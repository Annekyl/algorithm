#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n, m, st, ed;

void solve() {
    cin >> n >> m >> st >> ed;
    vector<pii> g[n + 1];
    while (m--) {
        int x, y, v;
        cin >> x >> y >> v;
        g[x].push_back({y, v});
        g[y].push_back({x, v});	// ⚠️双向边
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << ":";
    //     for (auto [y, z] : g[i]) {
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }

    int d[n + 1];
    memset(d, 0x3f, sizeof d);
    d[st] = 0;

    queue<int> q;
    q.push(st);

    bool v[n + 1];
    memset(v, 0, sizeof v);
    v[st] = true;
    while (q.size()) {
        int x = q.front();
        q.pop();
        // cout << x << endl;
        v[x] = false;
        for (auto [y, z] : g[x]) {
            // debug(y);
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) {
                    q.push(y);
                    v[y] = true;
                }
            }
        }
    }
    cout << d[ed] << endl;
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
