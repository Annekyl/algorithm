// 最长公共子序列 (LCS - Longest Common Subsequence)
// AcWing 897. 最长公共子序列
// 给定两个序列，找出它们的最长公共子序列的长度
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)，可优化到 O(min(n, m))
// 转移方程：f[i][j] = max(f[i-1][j], f[i][j-1], f[i-1][j-1] + (a[i]==b[j]))

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N]; // f[i][j]: a 的前 i 个字符和 b 的前 j 个字符的 LCS 长度

// ==================== O(nm) DP ====================
// 转移：
//   若 a[i] == b[j]：f[i][j] = f[i-1][j-1] + 1
//   否则：f[i][j] = max(f[i-1][j], f[i][j-1])
int lcs() {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    return f[n][m];
}

// 输出 LCS 的具体内容
// 从 f[n][m] 逆向追踪，找到构成 LCS 的字符
void print_lcs() {
    int len = lcs();
    char res[N];
    int idx = len;

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            res[idx--] = a[i]; // 这个字符属于 LCS
            i--, j--;
        } else if (f[i - 1][j] > f[i][j - 1]) {
            i--; // 向上走
        } else {
            j--; // 向左走
        }
    }

    for (int k = 1; k <= len; k++)
        printf("%c", res[k]);
    printf("\n");
}

// ==================== 空间优化 ====================
// 利用滚动数组，将空间从 O(nm) 优化到 O(m)
// 注意：需要记录 f[i-1][j-1] 的值（用 prev 变量）
int lcs_optimized() {
    int dp[N];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        int prev = 0; // 记录 f[i-1][j-1]
        for (int j = 1; j <= m; j++) {
            int temp = dp[j]; // 保存当前 dp[j]（即 f[i-1][j]）
            if (a[i] == b[j]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = temp; // 更新 prev
        }
    }

    return dp[m];
}

// ==================== 最长公共子串 (连续) ====================
// 与 LCS 不同，子串必须是连续的
// 转移：若 a[i] == b[j]，f[i][j] = f[i-1][j-1] + 1
int lcs_substring() {
    memset(f, 0, sizeof f);
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                res = max(res, f[i][j]);
            }
        }
    }

    return res;
}

int main() {
    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);

    printf("%d\n", lcs());

    return 0;
}
