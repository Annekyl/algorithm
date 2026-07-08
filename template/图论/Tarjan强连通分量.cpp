// Tarjan算法 - 强连通分量 (SCC)
// AcWing 1174. 受欢迎的牛 / 367. 学校网络
// 强连通分量：有向图中一个最大的点集，其中任意两点互相可达
// Tarjan 算法：用一次 DFS 求出所有强连通分量
// 时间复杂度：O(n + m)
// 核心概念：
//   dfn[u]: u 的 DFS 序（时间戳）
//   low[u]: u 及其子树中能到达的最小 dfn 值
//   栈 stk: 存储当前 DFS 路径上的节点
//   当 dfn[u] == low[u] 时，u 是一个 SCC 的根

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 50010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx; // 邻接表
int dfn[N], low[N], timestamp; // dfn: DFS序, low: 能到达的最小dfn
int stk[N], top;              // 手动实现栈
bool in_stk[N];               // in_stk[i]: i 是否在栈中
int id[N], scc_cnt, size[N]; // id[i]: i 所属的 SCC 编号, scc_cnt: SCC 数量

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// Tarjan DFS
// 对于每个节点 u：
//   1. 记录 dfn 和 low，入栈
//   2. 遍历所有邻居 v：
//      - v 未访问：递归，用 low[v] 更新 low[u]
//      - v 在栈中：用 dfn[v] 更新 low[u]（注意：这里用 dfn[v] 而非 low[v]）
//   3. 如果 dfn[u] == low[u]，u 是 SCC 的根，弹出栈中节点直到 u
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {          // v 未访问
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v]) { // v 在栈中（v 是 u 的祖先）
            low[u] = min(low[u], dfn[v]);
        }
    }

    // u 是 SCC 的根，弹出整个 SCC
    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int y;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            size[scc_cnt]++;
        } while (y != u);
    }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    printf("%d\n", scc_cnt);

    return 0;
}
