// 网络流 - 最大流 (Dinic)
// AcWing 1017. 怪兽游戏 / 2175. 飞行员兄弟
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1210, M = 200010, INF = 1e9;

int n, m, s, t;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    memset(d, -1, sizeof d);
    int hh = 0, tt = 0;
    q[0] = s, d[s] = 0, cur[s] = h[s];

    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if (v == t) return true;
                q[++tt] = v;
            }
        }
    }
    return false;
}

int dinic(int u, int limit) {
    if (u == t) return limit;
    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int v = e[i];
        if (d[v] == d[u] + 1 && f[i]) {
            int t = dinic(v, min(f[i], limit - flow));
            if (!t) d[v] = -1;
            else {
                f[i] -= t, f[i ^ 1] += t;
                flow += t;
            }
        }
    }

    return flow;
}

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
