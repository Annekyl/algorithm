#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 25;

int n;
int dp[1 << 20][20];
int weight[MAX_N][MAX_N];

void hamilton() {
    // 路径先初始化为无穷大
    memset(dp, 0x3f, sizeof dp);

    // 起点的路径长度为0
    dp[1][0] = 0;

    // 遍历所有可能状态：每个点是否经过
    for (int state = 1; state < 1 << n; state++)
        // 遍历当前状态下的每个节点j
        for (int j = 0; j < n; j++)
            // 判断当前状态下包含节点j
            if (state >> j & 1)
                // 尝试从其他已经访问过的节点k转移到j，得到当前的状态
                for (int k = 0; k < n; k++)
                    // 判断当前状态是否包含节点k
                    // 右移运算的优先级高于异或
                    // state ^ 1 << j 于当前状态相比，只不包含j
                    // 如果含有节点 k，则更新经过k到j的状态
                    if ((state ^ 1 << j) >> k & 1)
                        // 状态转移
                        dp[state][j] = min(dp[state][j], dp[state ^ 1 << j][k] +
                                                             weight[k][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> weight[i][j];

    hamilton();
    cout << dp[(1 << n) - 1][n - 1];

    return 0;
}