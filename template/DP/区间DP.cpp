// 区间DP (Interval DP)
// AcWing 282. 石子合并 / 1068. 石子游戏
// 在区间上进行动态规划，将大区间分解为小区间
// 核心思想：
//   1. 枚举区间长度
//   2. 枚举区间起点
//   3. 枚举分割点，合并两个子区间
// 时间复杂度：O(n^3)
// 转移：f[l][r] = min(f[l][k] + f[k+1][r] + cost(l, r))，l <= k < r

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n;
int s[N], f[N][N]; // s: 前缀和, f[l][r]: 区间 [l, r] 的最优解

// ==================== 石子合并 (环形) ====================
// 将 n 堆石子排成环，每次合并相邻两堆，求最小代价
// 环形处理：将数组复制一份，变成长度为 2n 的链
// 时间复杂度：O(n^3)
void interval_dp_circle() {
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    // 环形处理：复制一倍
    for (int i = 1; i <= n; i++) s[i + n] = s[i] + s[n];

    memset(f, 0x3f, sizeof f);
    // 枚举区间长度
    for (int len = 1; len <= n; len++) {
        // 枚举区间起点
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = 0; // 长度为 1，代价为 0
                continue;
            }
            // 枚举分割点
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    // 枚举所有长度为 n 的区间的最小值
    int res = 1e9;
    for (int i = 1; i <= n; i++)
        res = min(res, f[i][i + n - 1]);
    printf("%d\n", res);
}

// ==================== 石子合并 (链式) ====================
// 将 n 堆石子排成一行，每次合并相邻两堆，求最小代价
void interval_dp_chain() {
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = 0;
                continue;
            }
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    printf("%d\n", f[1][n]);
}

// ==================== 矩阵链乘法 ====================
// 给定 n 个矩阵的维度，求使得乘法次数最少的括号化方案
// p[i-1] x p[i] 是第 i 个矩阵的维度
// 转移：f[l][r] = min(f[l][k] + f[k+1][r] + p[l-1] * p[k] * p[r])
void matrix_chain() {
    int p[N];
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);

    memset(f, 0x3f, sizeof f);
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = 0; // 单个矩阵，乘法次数为 0
                continue;
            }
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + p[l - 1] * p[k] * p[r]);
            }
        }
    }

    printf("%d\n", f[1][n - 1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

    interval_dp_chain();

    return 0;
}
