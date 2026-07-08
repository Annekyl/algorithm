// 状压DP (状态压缩DP)
// AcWing 187. 导弹防御系统 / 189. 皇后的不同摆放方法
// 用二进制位表示状态，适用于 n 较小（通常 n <= 20）的问题
// 典型应用：
//   1. N皇后问题
//   2. 旅行商问题 (TSP)
//   3. 棋盘覆盖
// 时间复杂度：O(2^n * n)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, m;
int dp[N]; // dp[i]: 状态 i 下的方案数

// ==================== 皇后的不同摆放方法 (N皇后) ====================
// 用三个数组记录列、主对角线、副对角线是否被占用
// col[i]: 第 i 列是否被占用
// dg[i]: 主对角线（行 - 列 + n）是否被占用
// udg[i]: 副对角线（行 + 列）是否被占用
int queen() {
    int ans = 0;
    int col[N], dg[N], udg[N];

    function<void(int)> dfs = [&](int row) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col_idx = 0; col_idx < n; col_idx++) {
            if (!col[col_idx] && !dg[row - col_idx + n] && !udg[row + col_idx]) {
                col[col_idx] = dg[row - col_idx + n] = udg[row + col_idx] = 1;
                dfs(row + 1);
                col[col_idx] = dg[row - col_idx + n] = udg[row + col_idx] = 0;
            }
        }
    };

    dfs(0);
    return ans;
}

// ==================== 旅行商问题 (TSP) ====================
// 给定 n 个城市和两两之间的距离，求从城市 0 出发，访问所有城市一次并回到 0 的最短路径
// f[S][i]: 访问了 S 集合中的城市，当前在城市 i 的最小距离
// 转移：f[S | (1<<j)][j] = min(f[S | (1<<j)][j], f[S][i] + dist[i][j])
int dist[N][N];
int f[1 << N][N]; // f[S][i]: 访问了S集合中的城市，当前在i的最小距离

int tsp() {
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; // 从城市 0 出发

    for (int s = 1; s < (1 << n); s++) { // 枚举状态
        for (int i = 0; i < n; i++) {    // 枚举当前城市
            if (!(s >> i & 1)) continue; // i 不在 S 中
            for (int j = 0; j < n; j++) { // 枚举下一个城市
                if (s >> j & 1) continue; // j 已在 S 中
                f[s | (1 << j)][j] = min(f[s | (1 << j)][j], f[s][i] + dist[i][j]);
            }
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; i++)
        res = min(res, f[(1 << n) - 1][i] + dist[i][0]); // 回到城市 0

    return res;
}

// ==================== 最短哈密尔顿路径 ====================
// 从城市 0 出发，访问所有城市一次的最短路径（不要求回到起点）
int hamilton() {
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for (int s = 1; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            if (!(s >> i & 1)) continue;
            for (int j = 0; j < n; j++) {
                if (s >> j & 1) continue;
                f[s | (1 << j)][j] = min(f[s | (1 << j)][j], f[s][i] + dist[i][j]);
            }
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; i++)
        res = min(res, f[(1 << n) - 1][i]); // 不需要回到起点

    return res;
}

// ==================== 蒙德里安的梦想 (棋盘覆盖) ====================
// 用 1x2 的骨牌覆盖 n x m 的棋盘，求方案数
// 核心：逐列处理，每列的状态表示哪些格子被上一列的骨牌覆盖
// 合法状态：连续的 0 必须有偶数个（可以被 1x2 骨牌覆盖）
int count_tiling() {
    int cnt = 0;
    int state[1 << 12]; // 存储所有合法状态

    // 预处理合法状态
    for (int s = 0; s < (1 << m); s++) {
        bool ok = true;
        int ones = 0;
        for (int j = 0; j < m; j++) {
            if (s >> j & 1) {
                if (ones & 1) { // 连续 0 的个数为奇数，不合法
                    ok = false;
                    break;
                }
                ones = 0;
            } else {
                ones++;
            }
        }
        if (ones & 1) ok = false; // 最后一段连续 0 为奇数
        if (ok) state[cnt++] = s;
    }

    memset(dp, 0, sizeof dp);
    dp[0] = 1; // 初始状态：全 0

    // 逐列转移
    for (int i = 0; i < n; i++) {
        int new_dp[1 << 12] = {0};
        for (int j = 0; j < cnt; j++) {
            int s = state[j];
            for (int k = 0; k < cnt; k++) {
                int prev_s = state[k];
                if ((s & prev_s) == 0) { // 当前列和上一列无冲突
                    new_dp[s] += dp[prev_s];
                }
            }
        }
        memcpy(dp, new_dp, sizeof dp);
    }

    return dp[(1 << m) - 1]; // 所有格子都被覆盖
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    printf("%d\n", tsp());

    return 0;
}
