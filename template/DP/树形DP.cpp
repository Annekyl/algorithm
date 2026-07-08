// 树形DP (Tree DP)
// AcWing 1072. 树的最长路径 / 1073. 树的中心 / 1075. 数字转换
// 在树结构上进行动态规划，利用 DFS 从叶子向根传递信息
// 典型应用：
//   1. 树的直径（最长路径）
//   2. 树的中心
//   3. 树上最大/最小权独立集
// 时间复杂度：O(n)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int h[N], e[N], ne[N], idx; // 邻接表
int d1[N], d2[N], up[N];    // d1: 最长路径, d2: 次长路径, up: 向上的最长路径

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ==================== 树的最长路径 ====================
// 第一遍 DFS：计算每个节点向下的最长路径和次长路径
// d1[u]: 以 u 为根的子树中，从 u 向下的最长路径
// d2[u]: 以 u 为根的子树中，从 u 向下的次长路径
void dfs1(int u, int fa) {
    d1[u] = d2[u] = 0;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue; // 不走回头路
        dfs1(v, u);

        int dist = d1[v] + 1;
        if (dist > d1[u]) {
            d2[u] = d1[u]; // 原来的最长变次长
            d1[u] = dist;  // 更新最长
        } else if (dist > d2[u]) {
            d2[u] = dist;  // 更新次长
        }
    }
}

// 第二遍 DFS：计算每个节点向上的最长路径
// up[u]: 从 u 向上（经过父节点）的最长路径
void dfs2(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;

        if (d1[u] - 1 != d1[v])
            up[v] = max(up[u], d1[u]) + 1; // u 的最长路径不经过 v
        else
            up[v] = max(up[u], d2[u]) + 1; // u 的最长路径经过 v，用次长

        dfs2(v, u);
    }
}

// 树的中心：所有节点中最远距离最小的节点
// 最远距离 = max(向下最长, 向上最长)
int center() {
    dfs1(1, -1);
    dfs2(1, -1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, max(d1[i], up[i]));

    return res;
}

// ==================== 树上最大独立集 ====================
// 独立集：选一些不相邻的节点，使得总数最大
// f[u][0]: 不选 u 时的最大独立集大小
// f[u][1]: 选 u 时的最大独立集大小
int f[N][2]; // f[u][0]: 不选u, f[u][1]: 选u

void dfs_mis(int u, int fa) {
    f[u][0] = 0;  // 不选 u
    f[u][1] = 1;  // 选 u

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs_mis(v, u);
        f[u][0] += max(f[v][0], f[v][1]); // 不选 u，子节点可选可不选
        f[u][1] += f[v][0];               // 选 u，子节点不能选
    }
}

// ==================== 树上最大权独立集 ====================
// 每个节点有权值，选不相邻的节点使权值和最大
int w[N];
void dfs_mwis(int u, int fa) {
    f[u][0] = 0;
    f[u][1] = w[u]; // 初始值为自身权值

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs_mwis(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

// ==================== 树上直径（两遍 DFS） ====================
// 从任意点出发，找到最远点 A；再从 A 出发，找到最远点 B
// A 到 B 的距离就是树的直径
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
    dfs_diameter(1, -1);  // 第一遍：找到最远点 A
    int start = max_node;

    max_dist = 0;
    dist[start] = 0;
    dfs_diameter(start, -1); // 第二遍：从 A 出发找最远点 B

    return max_dist;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a); // 无向图
    }

    printf("%d\n", get_diameter());

    return 0;
}
