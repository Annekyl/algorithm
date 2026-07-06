// 状压DP (状态压缩DP)
// AcWing 187. 导弹防御系统 / 189. 皇后的不同摆放方法
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, m;
int dp[N]; // dp[i]: i状态下的方案数

// 皇后的不同摆放方法 (N皇后)
int queen() {
    int ans = 0;
    // col: 列, dg: 主对角线, udg: 副对角线
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

// 旅行商问题 (TSP)
int dist[N][N];
int f[1 << N][N]; // f[S][i]: 访问了S集合中的城市，当前在i的最小距离

int tsp() {
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
        res = min(res, f[(1 << n) - 1][i] + dist[i][0]);

    return res;
}

// 最短哈密尔顿路径
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
        res = min(res, f[(1 << n) - 1][i]);

    return res;
}

// 蒙德里安的梦想 (棋盘覆盖)
int count_tiling() {
    int cnt = 0;
    int state[1 << 12];

    // 预处理合法状态
    for (int s = 0; s < (1 << m); s++) {
        bool ok = true;
        int ones = 0;
        for (int j = 0; j < m; j++) {
            if (s >> j & 1) {
                if (ones & 1) {
                    ok = false;
                    break;
                }
                ones = 0;
            } else {
                ones++;
            }
        }
        if (ones & 1) ok = false;
        if (ok) state[cnt++] = s;
    }

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int new_dp[1 << 12] = {0};
        for (int j = 0; j < cnt; j++) {
            int s = state[j];
            for (int k = 0; k < cnt; k++) {
                int prev_s = state[k];
                if ((s & prev_s) == 0) {
                    new_dp[s] += dp[prev_s];
                }
            }
        }
        memcpy(dp, new_dp, sizeof dp);
    }

    return dp[(1 << m) - 1];
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    printf("%d\n", tsp());

    return 0;
}
