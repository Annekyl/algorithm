// 最短Hamilton路径 (状压DP)
// AcWing 91. 最短Hamilton路径
// 给定 n 个城市和两两之间的距离，求从城市 0 到城市 n-1 的最短哈密尔顿路径
// 哈密尔顿路径：恰好经过每个城市一次的路径
// 时间复杂度：O(2^n * n^2)
// 状态定义：f[S][i] = 访问了 S 集合中的城市，当前在城市 i 的最小距离
// 转移：f[S | (1<<j)][j] = min(f[S | (1<<j)][j], f[S][i] + w[i][j])

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
int w[N][N];         // w[i][j]: 城市 i 到 j 的距离
int f[1 << N][N];    // f[S][i]: 访问了S集合中的城市，当前在i的最小距离

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; // 初始状态：只访问了城市 0，当前在城市 0

    // 枚举所有状态
    for (int s = 1; s < (1 << n); s++) { // s: 已访问城市的集合
        for (int i = 0; i < n; i++) {    // i: 当前所在城市
            if (!(s >> i & 1)) continue; // i 不在已访问集合中，跳过
            for (int j = 0; j < n; j++) { // j: 下一个要访问的城市
                if (s >> j & 1) continue; // j 已访问过，跳过
                // 从 i 走到 j，更新状态
                f[s | (1 << j)][j] = min(f[s | (1 << j)][j], f[s][i] + w[i][j]);
            }
        }
    }

    // 最终答案：访问所有城市，当前在城市 n-1
    printf("%d\n", f[(1 << n) - 1][n - 1]);

    return 0;
}
