// 最短路算法
// Dijkstra / Bellman-Ford / SPFA / Floyd
// AcWing 849. Dijkstra求最短路 / 854. Floyd求最短路
// 适用场景：
//   Dijkstra: 非负权图，单源最短路，O((n+m)log n)
//   Bellman-Ford: 可处理负权边和负环，O(nm)
//   SPFA: 队列优化的 Bellman-Ford，平均 O(m)，最坏 O(nm)
//   Floyd: 多源最短路，O(n^3)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, m, s;
int h[N], e[N], ne[N], idx, w[N]; // 邻接表存图
int dist[N];                        // dist[i]: 源点到 i 的最短距离
bool st[N];                         // st[i]: i 是否已确定最短路

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

// Dijkstra (堆优化) - 非负权图
// 核心：每次从未确定的节点中选距离最小的，用它更新其他节点
// 时间复杂度：O((n + m) log n)
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, s});

    while (heap.size()) {
        auto [d, u] = heap.top();
        heap.pop();
        if (st[u]) continue; // 已确定最短路，跳过
        st[u] = true;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > d + w[i]) {
                dist[v] = d + w[i];
                heap.push({dist[v], v});
            }
        }
    }
}

// Bellman-Ford - 可处理负权边
// 核心：进行 n-1 轮松弛操作，每轮尝试用所有边更新距离
// 优化：如果某轮没有更新，提前退出
void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) { // 最多 n-1 轮
        bool flag = false;
        for (int u = 0; u <= n; u++) {
            for (int j = h[u]; ~j; j = ne[j]) {
                int v = e[j];
                if (dist[v] > dist[u] + w[j]) {
                    dist[v] = dist[u] + w[j];
                    flag = true;
                }
            }
        }
        if (!flag) break; // 没有更新，提前退出
    }
}

// SPFA (队列优化 Bellman-Ford)
// 核心：只对可能被更新的节点进行松弛操作
// 时间复杂度：平均 O(m)，最坏 O(nm)（遇到负环或特殊构造）
void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    st[s] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
}

// SPFA 判断负环
// 核心：如果某个节点被松弛超过 n 次，则存在负环
// 将所有节点入队作为初始源点
bool spfa_negative_cycle() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    int cnt[N] = {0}; // cnt[i]: i 被松弛的次数

    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true; // 被松弛超过 n 次，存在负环
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
    return false;
}

// Floyd - 多源最短路
// 核心：动态规划，d[i][j] 表示从 i 到 j 的最短距离
// 转移：d[i][j] = min(d[i][j], d[i][k] + d[k][j])
// 时间复杂度：O(n^3)
int d[N][N];
void floyd() {
    // 初始化：自身距离为 0，其余为 INF
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    // 三重循环，枚举中转点 k
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i] == INF ? -1 : dist[i]);

    return 0;
}
