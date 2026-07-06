// 最小生成树
// Kruskal / Prim
// AcWing 859. Kruskal算法求最小生成树
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int p[N];
struct Edge {
    int a, b, w;
    bool operator<(const Edge &W) const {
        return w < W.w;
    }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// Kruskal算法
int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

// Prim算法
int g[N][N], dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (dist[t] == INF) return INF;
        st[t] = true;
        res += dist[t];

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
