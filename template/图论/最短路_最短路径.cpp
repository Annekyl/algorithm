// 最短路算法
// Dijkstra / Bellman-Ford / SPFA / Floyd
// AcWing 849. Dijkstra求最短路 / 854. Floyd求最短路
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, m, s;
int h[N], e[N], ne[N], idx, w[N];
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

// Dijkstra (堆优化) - 非负权图
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, s});

    while (heap.size()) {
        auto [d, u] = heap.top();
        heap.pop();
        if (st[u]) continue;
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
void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
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
        if (!flag) break;
    }
}

// SPFA (队列优化Bellman-Ford)
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

// SPFA判断负环
bool spfa_negative_cycle() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    int cnt[N] = {0};

    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
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
int d[N][N];
void floyd() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

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
