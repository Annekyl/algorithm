// 网络流 - 最小费用最大流 (MCMF - Minimum Cost Maximum Flow)
// AcWing 2176. 加班问题
// 在容量网络中，求从源点 s 到汇点 t 的最大流的最小费用
// SPFA + 增广路算法：
//   1. 用 SPFA 找到从 s 到 t 的最短增广路（按费用）
//   2. 沿增广路增加流量，更新费用
//   3. 重复直到无法增广
// 时间复杂度：O(F * nm)，F 为最大流

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510, M = 15010, INF = 1e9;

int n, m, s, t;
int h[N], e[M], f[M], w[M], ne[M], idx; // 邻接表, f: 容量, w: 费用
int dist[N], incf[N], pre[N];           // dist: 距离, incf: 增广量, pre: 前驱边
bool st[N];                             // SPFA 的 in_queue 标记

// 添加边（正向边 + 反向边，反向边费用取负）
void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}

// SPFA 找最短增广路
// 在残量网络上找从 s 到 t 的最短路（按费用）
// 返回 true 表示存在增广路
bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(incf, 0, sizeof incf);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    incf[s] = INF;

    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i] && f[i]) { // 有容量且可松弛
                dist[v] = dist[u] + w[i];
                incf[v] = min(incf[u], f[i]); // 记录可增广的流量
                pre[v] = i;                    // 记录前驱边
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }

    return incf[t] > 0; // 汇点有可增广的流量
}

// 主函数：循环 SPFA 增广
int mcmf() {
    int cost = 0, flow = 0;
    while (spfa()) {
        int x = t;
        flow += incf[t];
        cost += incf[t] * dist[t]; // 费用 = 流量 * 单位费用
        // 沿增广路更新容量
        while (x != s) {
            int i = pre[x];
            f[i] -= incf[t];       // 正向边减
            f[i ^ 1] += incf[t];   // 反向边加
            x = e[i ^ 1];
        }
    }
    return cost;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    s = 0, t = n + m + 1;

    // 建图略（根据具体题目构造网络）
    // for (int i = 1; i <= n; i++) add(s, i, ...);
    // for (int i = 1; i <= m; i++) add(i + n, t, ...);

    printf("%d\n", mcmf());

    return 0;
}
