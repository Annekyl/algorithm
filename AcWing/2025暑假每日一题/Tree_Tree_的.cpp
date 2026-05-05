#include "bits/stdc++.h"

// #define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 15;

int n, m;
set<int> g[N];
int mx1, mx2; // 最大子图和次大子图的节点数
int d[N];

void dfs(int x, int dis) {
    d[x] = dis;
    for (auto y : g[x]) {
        if (!d[y]) {
            dfs(y, dis + 1);
        } else {
            // 找到自环，更新最大子图和次大子图
            int sz = d[x] - d[y] + 1;
            if (sz > mx1) {
                mx2 = mx1;
                mx1 = sz;
            } else if (sz < mx1 && sz > mx2) {
                mx2 = sz;
            }
        }
    }
    d[x] = 0; // 回溯
}

void solve() {
    cin >> n >> m;

    mx1 = 1, mx2 = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        // 跳过自环
        if (x == y)
            continue;
        mx1 = 2, mx2 = 1;
        g[x].insert(y);
        g[y].insert(x);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 1);
    }

    cout << mx1 << " " << mx2 << endl;
    // 清空邻接表
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}