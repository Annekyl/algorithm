// 最近公共祖先 (LCA - Lowest Common Ancestor)
// 倍增法 / Tarjan离线 / 树链剖分
// AcWing 1172. 王国祭祀 / 886. 求组合数
// LCA(a, b): 节点 a 和 b 的最近公共祖先
// 倍增法：
//   1. 预处理每个节点的 2^k 级祖先
//   2. 先将两个节点跳到同一深度
//   3. 再同时向上跳，直到 LCA 的下一层
// 时间复杂度：预处理 O(n log n)，查询 O(log n)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40010, LOG = 16; // LOG: log2(N)

int n, m, root;
int h[N], e[N], ne[N], idx;    // 邻接表
int depth[N], fa[N][LOG];      // depth: 深度, fa[i][k]: i 的 2^k 级祖先

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// BFS 预处理深度和倍增数组
// fa[v][0] = parent(v)
// fa[v][k] = fa[fa[v][k-1]][k-1]
void bfs() {
    memset(depth, -1, sizeof depth);
    depth[root] = 0;
    queue<int> q;
    q.push(root);

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (depth[v] == -1) {
                depth[v] = depth[t] + 1;
                fa[v][0] = t; // 父节点
                // 倍增：预处理 2^k 级祖先
                for (int k = 1; k < LOG; k++)
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                q.push(v);
            }
        }
    }
}

// 倍增法求 LCA
// 1. 将 a 跳到与 b 同一深度
// 2. 如果 a == b，直接返回
// 3. 同时向上跳，直到 LCA 的下一层
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    // 将 a 跳到与 b 同一深度
    for (int k = LOG - 1; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    // 同时向上跳
    for (int k = LOG - 1; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0]; // 返回 LCA
}

// 路径距离
// dist(a, b) = depth(a) + depth(b) - 2 * depth(LCA(a, b))
int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == -1) root = a; // 根节点
        else add(a, b), add(b, a);
    }

    bfs();

    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if (p == a) printf("1\n");      // a 是 b 的祖先
        else if (p == b) printf("2\n"); // b 是 a 的祖先
        else printf("0\n");             // 否则
    }

    return 0;
}
