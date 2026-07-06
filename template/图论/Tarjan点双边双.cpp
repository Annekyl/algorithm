// Tarjan算法 - 点双连通分量 / 边双连通分量
// AcWing 1184. 欧拉回路 / 395. 冗余路径
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 50010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 点双连通分量
int dcc_cnt;
vector<int> dcc[N];
int cut[N]; // 割点
stack<int> stk;

void tarjan_bcc(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    int child = 0;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            child++;
            tarjan_bcc(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                dcc_cnt++;
                int y;
                do {
                    y = stk.top();
                    stk.pop();
                    dcc[dcc_cnt].push_back(y);
                } while (y != v);
                dcc[dcc_cnt].push_back(u);
                if (u != root || child > 1) cut[u] = true;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// 边双连通分量
int ebcc_cnt;
int ebcc[N];
bool bridge[M];

void tarjan_ebcc(int u, int from) {
    dfn[u] = low[u] = ++timestamp;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan_ebcc(v, i);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) {
                bridge[i] = bridge[i ^ 1] = true;
            }
        } else if (i != (from ^ 1)) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void find_ebcc() {
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan_ebcc(i, -1);

    for (int i = 1; i <= n; i++)
        if (!ebcc[i]) {
            ebcc_cnt++;
            // BFS/DFS标记ebcc
        }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i]) {
            root = i;
            tarjan_bcc(i);
        }

    printf("%d\n", dcc_cnt);

    return 0;
}
