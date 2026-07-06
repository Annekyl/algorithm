// 网络流 - 最小费用最大流 (MCMF)
// AcWing 2176. 加班问题
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510, M = 15010, INF = 1e9;

int n, m, s, t;
int h[N], e[M], f[M], w[M], ne[M], idx;
int dist[N], incf[N], pre[N];
bool st[N];

void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(incf, 0, sizeof incf);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    incf[s] = INF;

    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i] && f[i]) {
                dist[v] = dist[u] + w[i];
                incf[v] = min(incf[u], f[i]);
                pre[v] = i;
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }

    return incf[t] > 0;
}

int mcmf() {
    int cost = 0, flow = 0;
    while (spfa()) {
        int x = t;
        flow += incf[t];
        cost += incf[t] * dist[t];
        while (x != s) {
            int i = pre[x];
            f[i] -= incf[t];
            f[i ^ 1] += incf[t];
            x = e[i ^ 1];
        }
    }
    return cost;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    s = 0, t = n + m + 1;

    // 建图略
    // for (int i = 1; i <= n; i++) add(s, i, ...);
    // for (int i = 1; i <= m; i++) add(i + n, t, ...);

    printf("%d\n", mcmf());

    return 0;
}
