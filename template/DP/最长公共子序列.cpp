// 最长公共子序列 (LCS)
// AcWing 897. 最长公共子序列
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N]; // f[i][j]: a的前i个字符和b的前j个字符的LCS长度

// O(nm) DP
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

// 输出LCS
void print_lcs() {
    int len = lcs();
    char res[N];
    int idx = len;

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            res[idx--] = a[i];
            i--, j--;
        } else if (f[i - 1][j] > f[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int k = 1; k <= len; k++)
        printf("%c", res[k]);
    printf("\n");
}

// 空间优化
int lcs_optimized() {
    int dp[N];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        int prev = 0;
        for (int j = 1; j <= m; j++) {
            int temp = dp[j];
            if (a[i] == b[j]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }

    return dp[m];
}

// 最长公共子串 (连续)
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
