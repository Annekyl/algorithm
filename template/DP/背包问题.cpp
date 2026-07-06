// 背包问题
// 01背包 / 完全背包 / 多重背包 / 混合背包
// AcWing 2. 01背包问题 / 3. 完全背包问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

// 01背包 (空间优化)
void knapsack_01() {
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
}

// 完全背包 (空间优化)
void knapsack_complete() {
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
}

// 多重背包 (二进制优化)
const int M = 2010;
int v2[M], w2[M], cnt2;
int dp[N];

void knapsack_multi() {
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);
        int k = 1;
        while (k <= s) {
            v2[++cnt2] = a * k;
            w2[cnt2] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            v2[++cnt2] = a * s;
            w2[cnt2] = b * s;
        }
    }

    // 转化为01背包
    for (int i = 1; i <= cnt2; i++)
        for (int j = m; j >= v2[i]; j--)
            dp[j] = max(dp[j], dp[j - v2[i]] + w2[i]);
}

// 多重背包 (单调队列优化)
int g[N], q[N];

void knapsack_multi_queue() {
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof f);

        for (int j = 0; j < v; j++) {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v) {
                while (hh <= tt && q[hh] < k - s * v) hh++;
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
}

// 分组背包
void knapsack_group() {
    for (int i = 1; i <= n; i++) {
        int s;
        scanf("%d", &s);
        int v[N], w[N];
        for (int j = 1; j <= s; j++)
            scanf("%d%d", &v[j], &w[j]);

        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s; k++)
                if (j >= v[k])
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);

    knapsack_01();

    printf("%d\n", f[m]);

    return 0;
}
