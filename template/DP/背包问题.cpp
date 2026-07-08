// 背包问题 (Knapsack Problem)
// 01背包 / 完全背包 / 多重背包 / 混合背包
// AcWing 2. 01背包问题 / 3. 完全背包问题
// 经典动态规划问题，根据物品选择策略分为多种类型
// 核心思想：dp[i] 表示容量为 i 时的最大价值

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N]; // v: 体积, w: 价值
int f[N];       // f[j]: 容量为 j 时的最大价值

// ==================== 01背包 ====================
// 每个物品只能选一次
// 转移：f[j] = max(f[j], f[j - v[i]] + w[i])
// 关键：逆序遍历容量，确保每个物品只用一次
void knapsack_01() {
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--) // 逆序！
            f[j] = max(f[j], f[j - v[i]] + w[i]);
}

// ==================== 完全背包 ====================
// 每个物品可以选无限次
// 转移：f[j] = max(f[j], f[j - v[i]] + w[i])
// 关键：正序遍历容量，允许重复选择
void knapsack_complete() {
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++) // 正序！
            f[j] = max(f[j], f[j - v[i]] + w[i]);
}

// ==================== 多重背包 (二进制优化) ====================
// 每个物品最多选 s 个
// 优化：将 s 个物品拆分成 2^0, 2^1, 2^2, ... 个的组合
// 这样可以用 01 背包处理，将时间从 O(nms) 优化到 O(nm log s)
const int M = 2010;
int v2[M], w2[M], cnt2;
int dp[N];

void knapsack_multi() {
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);
        // 二进制拆分：将 s 拆分成 1, 2, 4, 8, ... 的组合
        int k = 1;
        while (k <= s) {
            v2[++cnt2] = a * k;
            w2[cnt2] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) { // 剩余部分
            v2[++cnt2] = a * s;
            w2[cnt2] = b * s;
        }
    }

    // 转化为 01 背包
    for (int i = 1; i <= cnt2; i++)
        for (int j = m; j >= v2[i]; j--)
            dp[j] = max(dp[j], dp[j - v2[i]] + w2[i]);
}

// ==================== 多重背包 (单调队列优化) ====================
// 时间复杂度：O(nm)
// 核心：对于每个余数 j (0 <= j < v)，用单调队列维护最优决策
int g[N], q[N]; // g: 上一轮的 f, q: 单调队列

void knapsack_multi_queue() {
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof f); // 备份上一轮的结果

        // 按余数分组处理
        for (int j = 0; j < v; j++) {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v) {
                // 移除超出范围的元素
                while (hh <= tt && q[hh] < k - s * v) hh++;
                // 维护单调递减队列
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
}

// ==================== 分组背包 ====================
// 物品分成若干组，每组最多选一个
// 转移：f[j] = max(f[j], f[j - v[k]] + w[k])，k 为组内物品
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
