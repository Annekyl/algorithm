// Tarjan算法 - 点双连通分量 (BCC) / 边双连通分量 (EBCC)
// AcWing 1184. 欧拉回路 / 395. 冗余路径
// 点双连通分量：极大子图中任意两点之间至少存在两条不相交的路径（除端点外）
//   - 割点：删除该点后，图不再连通
//   - 判断条件：low[v] >= dfn[u] 时，u 是割点
// 边双连通分量：极大子图中任意两点之间至少存在两条不相交的路径（不含公共边）
//   - 桥（割边）：删除该边后，图不再连通
//   - 判断条件：dfn[u] < low[v] 时，(u, v) 是桥
// 时间复杂度：O(n + m)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 50010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx; // 邻接表
int dfn[N], low[N], timestamp; // DFS序 和 能到达的最小dfn
int root;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ==================== 点双连通分量 ====================
// 利用栈存储路径上的节点，当 low[v] >= dfn[u] 时弹出一个点双
int dcc_cnt;
vector<int> dcc[N]; // dcc[i]: 第 i 个点双连通分量包含的节点
int cut[N];         // cut[i]: i 是否为割点
stack<int> stk;

void tarjan_bcc(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    int child = 0; // u 在 DFS 树中的子节点数

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            child++;
            tarjan_bcc(v);
            low[u] = min(low[u], low[v]);
            // low[v] >= dfn[u]：u 是割点，弹出一个点双
            if (low[v] >= dfn[u]) {
                dcc_cnt++;
                int y;
                do {
                    y = stk.top();
                    stk.pop();
                    dcc[dcc_cnt].push_back(y);
                } while (y != v);
                dcc[dcc_cnt].push_back(u);
                // 割点判定：根节点需要有至少两个子节点
                if (u != root || child > 1) cut[u] = true;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// ==================== 边双连通分量 ====================
// 桥的判定：dfn[u] < low[v] 时，(u, v) 是桥
int ebcc_cnt;
int ebcc[N];   // ebcc[i]: i 所属的边双连通分量编号
bool bridge[M]; // bridge[i]: 边 i 是否为桥

void tarjan_ebcc(int u, int from) {
    dfn[u] = low[u] = ++timestamp;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan_ebcc(v, i);
            low[u] = min(low[u], low[v]);
            // dfn[u] < low[v]：(u, v) 是桥
            if (dfn[u] < low[v]) {
                bridge[i] = bridge[i ^ 1] = true;
            }
        } else if (i != (from ^ 1)) { // 不是来时的边（反向边）
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// 标记边双连通分量（删除桥后用 BFS/DFS 标记连通块）
void find_ebcc() {
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan_ebcc(i, -1);

    for (int i = 1; i <= n; i++)
        if (!ebcc[i]) {
            ebcc_cnt++;
            // BFS/DFS 标记 ebcc（此处省略具体实现）
        }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a); // 无向图，加两条有向边
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i]) {
            root = i;
            tarjan_bcc(i);
        }

    printf("%d\n", dcc_cnt);

    return 0;
}
