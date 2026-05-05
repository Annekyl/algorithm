#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18; // 代表“无穷大”，比题目最大路径要大

// 边的结构体，表示一条从 u 到 v 的边，权重为 w
struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> E(m);
    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    // 特殊情况：只有一个点，最短路就是 0
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // 我们用“滚动数组”维护 dp
    // dp0[v] 表示恰好用 i-1 条边从 1 号点到 v 的最短距离
    // dp1[v] 表示恰好用 i 条边从 1 号点到 v 的最短距离
    vector<ll> dp0(n + 1, INF), dp1(n + 1, INF);
    dp0[1] = 0; // 用 0 条边到达 1 号点的距离为 0

    ll ans = INF; // 记录从 1 到 n 在 ≤k 条边内的最短距离

    // 外层循环表示“用 i 条边”进行一次松弛
    // 状态转移方程：
    // dp[i][v] = min_{(u->v,w) ∈ E}( dp[i-1][u] + w )
    for (int i = 1; i <= k; i++) {
        // 初始化 dp1 为 INF
        fill(dp1.begin(), dp1.end(), INF);

        // 遍历所有边，尝试从 dp0[u] 松弛到 dp1[v]
        for (auto &e : E) {
            if (dp0[e.u] < INF) {
                dp1[e.v] = min(dp1[e.v], dp0[e.u] + e.w);
            }
        }

        // 更新答案：恰好 i 条边到达 n 号点的最短
        ans = min(ans, dp1[n]);

        // 滚动：下一轮迭代时把 dp1 当作 dp0
        dp0.swap(dp1);
    }

    // 如果 ans 仍然是 INF，说明无法在 ≤k 条边内到达
    if (ans >= INF / 2) {
        cout << "impossible\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
