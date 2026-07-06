// 最近公共祖先 (LCA)
// 倍增法 / Tarjan离线 / 树链剖分
// AcWing 1172. 王国祭祀 / 886. 求组合数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40010, LOG = 16;

int n, m, root;
int h[N], e[N], ne[N], idx;
int depth[N], fa[N][LOG];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

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
                fa[v][0] = t;
                for (int k = 1; k < LOG; k++)
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                q.push(v);
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = LOG - 1; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = LOG - 1; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}

// 路径距离
int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == -1) root = a;
        else add(a, b), add(b, a);
    }

    bfs();

    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if (p == a) printf("1\n");
        else if (p == b) printf("2\n");
        else printf("0\n");
    }

    return 0;
}
