#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

struct cmp {
    bool operator()(const pii &a, const pii &b) const {
        return a.second < b.second;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<pii, vector<pii>, cmp> q;
    for (int i = 1; i <= n; i++) {
        q.push({i, g[i].size()});
    }
    int ans = 0;
    while (q.size()) {
        auto [id, cnt] = q.top();
        q.pop();
        ans += cnt * cnt;
        for (int y : g[id]) {
            q[y]--;
        }
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
