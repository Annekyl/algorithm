#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 2e5 + 10;

int n, x;
vi g[N];                // 图
int w[N], f[N];         // w: 权值 f: 存每个节点的父节点
int P[N], Q[N], mxQ[N]; // P: 原始最大值 Q: 异或后的路径最大值
// tin:节点进入的顺序, tout节点出去的顺序, timer记录访问顺序
// fs_order_P记录dfs路径上的P值
int tin[N], tout[N], timer, dfs_order_P[N];
int pre[N], suf[N];

void dfs(int u, int fa, int sumP, int sumQ) {
    f[u] = fa;
    tin[u] = ++timer;

    P[u] = sumP + w[u];
    Q[u] = sumQ + (w[u] ^ x);
    dfs_order_P[timer] = P[u];

    mxQ[u] = Q[u];
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u, P[u], Q[u]);
        mxQ[u] = max(mxQ[u], mxQ[v]);
    }

    tout[u] = timer;
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        g[i].clear();   // ⚠️多测，需要清空邻接表
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer = 0;
    dfs(1, 0, 0, 0);

    for (int i = 1; i <= n; i++) {
        pre[i] = max(pre[i - 1], dfs_order_P[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1], dfs_order_P[i]);
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        // 子树外的最大值
        int out_mx = max(pre[tin[i] - 1], suf[tout[i] + 1]);

        // 子树内的最大值
        int fa = f[i];
        int in_mx = mxQ[i] - Q[fa] + P[fa];

        int cur_mx = max(out_mx, in_mx);

        ans = min(ans, cur_mx);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
