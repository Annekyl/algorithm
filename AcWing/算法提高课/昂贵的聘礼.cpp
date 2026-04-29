#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

void solve() {
    int m, n;
    cin >> m >> n;
    int level[n + 1];
    vector<pii> g[n + 1];
    for (int i = 1; i <= n; i++) {
        int p, l, x;
        cin >> p >> l >> x;
        level[i] = l;
        g[0].push_back({i, p});
        while (x--) {
            int t, v;
            cin >> t >> v;
            g[t].push_back({i, v});
        }
    }

    // int ans = INF;
    // function<void(int, int)> dfs = [&](int x, int sum) -> void {
    //     if (sum >= ans)
    //         return;
    //     if (x == 1) {
    //         ans = sum;
    //         return;
    //     }

    //     for (auto [y, z] : g[x]) {
    //         if (level[y] + m < level[1])
    //             continue;
    //         dfs(y, sum + z);
    //     }
    // };

    // dfs(0, 0);

    vector<int> d(n + 1, 0x3f3f3f3f);
    vector<bool> v(n + 1, false);

    auto dijkstra = [&](int down, int up) -> int {
        fill(v.begin(), v.end(), false);      // ⚠️每次都需要重置v数组
        fill(d.begin(), d.end(), 0x3f3f3f3f); // ⚠️每次都要重置d数组
        d[0] = 0;                             // ⚠️注意起点注意也要重置为0
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, 0});
        while (q.size()) {
            int x = q.top().second;
            q.pop();
            if (v[x])
                continue;
            v[x] = true;
            for (auto [y, z] : g[x]) {
                if (level[y] < down || level[y] > up)
                    continue;
                if (d[y] > d[x] + z) {
                    d[y] = d[x] + z;
                    q.push({d[y], y});
                }
            }
        }

        return d[1];
    };

    int ans = INF;
    for (int i = level[1] - m; i <= level[1]; i++)
        ans = min(ans, dijkstra(i, i + m));
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
