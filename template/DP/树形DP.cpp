// 树形DP
// AcWing 1072. 树的最长路径 / 1073. 树的中心 / 1075. 数字转换
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int h[N], e[N], ne[N], idx;
int d1[N], d2[N], up[N]; // d1: 最长路径, d2: 次长路径, up: 向上的最长路径

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 树的最长路径
void dfs1(int u, int fa) {
    d1[u] = d2[u] = 0;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs1(v, u);

        int dist = d1[v] + 1;
        if (dist > d1[u]) {
            d2[u] = d1[u];
            d1[u] = dist;
        } else if (dist > d2[u]) {
            d2[u] = dist;
        }
    }
}

void dfs2(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;

        if (d1[u] - 1 != d1[v])
            up[v] = max(up[u], d1[u]) + 1;
        else
            up[v] = max(up[u], d2[u]) + 1;

        dfs2(v, u);
    }
}

// 树的中心
int center() {
    dfs1(1, -1);
    dfs2(1, -1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, max(d1[i], up[i]));

    return res;
}

// 树上最大独立集
int f[N][2]; // f[u][0]: 不选u, f[u][1]: 选u

void dfs_mis(int u, int fa) {
    f[u][0] = 0;
    f[u][1] = 1;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs_mis(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

// 树上最大权独立集
int w[N];
void dfs_mwis(int u, int fa) {
    f[u][0] = 0;
    f[u][1] = w[u];

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs_mwis(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

// 树上直径 (两遍DFS)
int dist[N], max_dist, max_node;

void dfs_diameter(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dist[v] = dist[u] + 1;
        if (dist[v] > max_dist) {
            max_dist = dist[v];
            max_node = v;
        }
        dfs_diameter(v, u);
    }
}

int get_diameter() {
    max_dist = 0;
    dist[1] = 0;
    dfs_diameter(1, -1);
    int start = max_node;

    max_dist = 0;
    dist[start] = 0;
    dfs_diameter(start, -1);

    return max_dist;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    printf("%d\n", get_diameter());

    return 0;
}
