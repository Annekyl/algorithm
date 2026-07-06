// 区间DP
// AcWing 282. 石子合并 / 1068. 石子游戏
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n;
int s[N], f[N][N];

// 石子合并 (环形)
void interval_dp_circle() {
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    // 环形处理：复制一倍
    for (int i = 1; i <= n; i++) s[i + n] = s[i] + s[n];

    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
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

    int res = 1e9;
    for (int i = 1; i <= n; i++)
        res = min(res, f[i][i + n - 1]);
    printf("%d\n", res);
}

// 石子合并 (链式)
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

// 矩阵链乘法
void matrix_chain() {
    int p[N];
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);

    memset(f, 0x3f, sizeof f);
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = 0;
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
