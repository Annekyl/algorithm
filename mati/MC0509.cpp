#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 3e5 + 10;

int n, m, k;
vi g[N];
bool st[N];

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<pii> q;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        q.push({x, 0});
        st[x] = true;
    }

    int ans = 0;
    while (q.size()) {
        auto [x, step] = q.front();
        q.pop();
        // cout << x << ' ';
        ans = max(ans, step);
        for (int y : g[x]) {
            if (st[y])
                continue;
            q.push({y, step + 1});
            st[y] = true;
        }
    }
    bool suc = true;
    for (int i = 1; i <= n; i++) {
        if (!st[i])
            suc = false;
    }

    if (suc)
        cout << ans << endl;
    else
        cout << -1 << endl;
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