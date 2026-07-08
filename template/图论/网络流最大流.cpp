// 网络流 - 最大流 (Dinic Algorithm)
// AcWing 1017. 怪兽游戏 / 2175. 飞行员兄弟
// 在容量网络中，从源点 s 到汇点 t 的最大流量
// Dinic 算法：
//   1. BFS 构建分层图（计算每个点的层数）
//   2. DFS 在分层图上寻找增广路（多路增广）
// 时间复杂度：O(n^2 * m)，实际运行很快
// 核心优化：
//   - 分层图：只沿层数严格递增的边增广
//   - 当前弧优化：cur[u] 记录 u 的起始搜索边，避免重复扫描

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1210, M = 200010, INF = 1e9;

int n, m, s, t;
int h[N], e[M], f[M], ne[M], idx; // 邻接表，f: 容量
int q[N], d[N], cur[N];           // q: BFS队列, d: 层数, cur: 当前弧

// 添加边（正向边 + 反向边）
void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

// BFS 构建分层图
// 从源点 s 开始 BFS，计算每个点的层数 d[]
// d[t] != -1 表示存在从 s 到 t 的增广路
bool bfs() {
    memset(d, -1, sizeof d);
    int hh = 0, tt = 0;
    q[0] = s, d[s] = 0, cur[s] = h[s]; // 初始化当前弧

    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (d[v] == -1 && f[i]) { // 未访问且有容量
                d[v] = d[u] + 1;
                cur[v] = h[v]; // 初始化当前弧
                if (v == t) return true; // 到达汇点
                q[++tt] = v;
            }
        }
    }
    return false;
}

// DFS 在分层图上寻找增广路
// u: 当前节点, limit: 当前可增广的流量上限
// 使用当前弧优化：cur[u] 记录 u 的起始搜索边
int dinic(int u, int limit) {
    if (u == t) return limit;
    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i; // 更新当前弧
        int v = e[i];
        if (d[v] == d[u] + 1 && f[i]) { // 在分层图上且有容量
            int t = dinic(v, min(f[i], limit - flow));
            if (!t) d[v] = -1; // 增广路阻塞
            else {
                f[i] -= t, f[i ^ 1] += t; // 更新容量
                flow += t;
            }
        }
    }

    return flow;
}

// 主函数：循环 BFS + DFS 直到无法增广
int maxflow() {
    int flow = 0;
    while (bfs())
        while (int r = dinic(s, INF))
            flow += r;
    return flow;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &s, &t);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    printf("%d\n", maxflow());

    return 0;
}
