#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用全局数组避免在栈上分配过大内存，限制为 N<=10000, M<=100
bool choice[10005][105];

int main() {
    // 优化输入输出流的速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // 1. 将硬币从大到小排序
    sort(coins.begin(), coins.end(), greater<int>());

    // dp[j] 表示是否能凑出金额 j
    vector<int> dp(m + 1, 0);
    dp[0] = 1; // 凑出金额 0 永远是可行的

    // 2. 动态规划过程
    for (int i = 1; i <= n; ++i) {
        int coin = coins[i - 1];
        // 0/1 背包，容量从大到小遍历
        for (int j = m; j >= coin; --j) {
            // 如果去掉当前硬币的金额能被凑出来，则当前金额也能被凑出来
            if (dp[j - coin]) {
                dp[j] = 1;
                choice[i][j] = true; // 记录路径：金额 j 可以通过选择第 i 个硬币凑出
            }
        }
    }

    // 3. 结果判断与回溯输出
    if (!dp[m]) {
        cout << "No Solution\n";
    } else {
        vector<int> res;
        int curr_m = m;
        // 逆序回溯，即优先选择靠后（面值较小）的硬币
        for (int i = n; i >= 1; --i) {
            if (choice[i][curr_m]) {
                res.push_back(coins[i - 1]);
                curr_m -= coins[i - 1];
            }
        }
        
        // 按题目要求的格式输出结果
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}