// Tarjan算法 - 强连通分量 (SCC)
// AcWing 1174. 受欢迎的牛 / 367. 学校网络
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 50010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, size[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

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
