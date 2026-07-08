// 最小生成树 (Minimum Spanning Tree, MST)
// Kruskal / Prim
// AcWing 859. Kruskal算法求最小生成树
// 两种经典算法：
//   Kruskal: 贪心 + 并查集，按边权排序依次加边，O(m log m)
//   Prim: 类似 Dijkstra，从一个点开始扩展，O(n^2)
// 适用场景：
//   Kruskal: 稀疏图
//   Prim: 稠密图

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N]; // 并查集
struct Edge {
    int a, b, w;
    bool operator<(const Edge &W) const {
        return w < W.w; // 按边权排序
    }
} edges[M];

// 并查集查找（带路径压缩）
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// Kruskal 算法
// 1. 将所有边按权值排序
// 2. 依次考虑每条边，如果两端点不在同一集合，则加入
// 3. 加入 n-1 条边后，最小生成树构建完成
int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i; // 初始化并查集

    int res = 0, cnt = 0; // res: 总权值, cnt: 已加入的边数
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) { // 不在同一集合，加入
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) return INF; // 边数不足，不连通
    return res;
}

// Prim 算法
// 核心：每次从未加入的点中选距离最小的点加入，并用它更新其他点的距离
int g[N][N], dist[N]; // g: 邻接矩阵, dist: 到生成树的最短距离
bool st[N];           // st[i]: i 是否已加入生成树

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 从点 1 开始
    int res = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        // 找距离最小的未加入点
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (dist[t] == INF) return INF; // 不连通
        st[t] = true;
        res += dist[t];

        // 用 t 更新其他点的距离
        for (int j = 1; j <= n; j++)
            if (!st[j] && g[t][j] < dist[j])
                dist[j] = g[t][j];
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int res = kruskal();
    if (res == INF) printf("impossible\n");
    else printf("%d\n", res);

    return 0;
}
