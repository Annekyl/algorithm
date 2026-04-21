#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> order;
    vector<int> parent(n + 1, 0);
    stack<int> stk;
    stk.push(1);
    while (stk.size()) {
        auto u = stk.top();
        stk.pop();
        order.push_back(u);
        for (auto v : g[u]) {
            if (v == parent[u])
                continue;
            parent[v] = u;
            stk.push(v);
        }
    }

    //     cout << order.size() << endl;
    //     return;

    vector<int> sz(n + 1, 1);
    int dp[n + 1][2];
    for (int i = order.size() - 1; i >= 0; i--) {
        int u = order[i];

        int dp0 = 0, dp1 = 1;
        for (int v : g[u]) {
            if (v != parent[u]) {
                sz[u] += sz[v];
                dp0 += max(dp[v][0], dp[v][1]);
                dp1 += dp[v][0];
            }
        }

        dp[u][0] = dp0;
        dp[u][1] = dp1;
    }

    //     return;

    for (int i = 1; i <= n; i++) {
        int mx = max(dp[i][0], dp[i][1]);
        int ans = sz[i] - mx;
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}