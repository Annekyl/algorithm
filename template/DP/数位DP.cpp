// 数位DP
// AcWing 1081. 度的数量 / 1082. 数字游戏 / 1083. windy数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int digits[N];
int f[N][N]; // f[i][j]: 长度为i，最高位为j的方案数

// 预处理
void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!i) f[i][j] = 1;
            else
                for (int k = 0; k < N; k++)
                    f[i][j] += f[i - 1][k];
}

// 数字计数 [l, r] 中满足条件的数的个数
int count(int n) {
    if (n == 0) return 1;

    int len = 0;
    while (n) {
        digits[++len] = n % 10;
        n /= 10;
    }

    int res = 0;
    // 枚举每一位
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < digits[i]; j++) {
            res += f[i][j]; // 位数为i，最高位为j的数
        }
    }

    return res;
}

// 计算不含前导零的数字个数
int count_no_leading_zero(int n) {
    if (n == 0) return 0;

    int len = 0;
    while (n) {
        digits[++len] = n % 10;
        n /= 10;
    }

    int res = 0;
    // 最高位不能为0
    for (int i = 1; i < digits[len]; i++) {
        res += f[len - 1][i];
    }

    // 剩余位数
    for (int i = len - 1; i >= 1; i--) {
        for (int j = 0; j < digits[i]; j++) {
            res += f[i - 1][j];
        }
    }

    return res;
}

// windy数 (相邻数字差至少为2)
int g[N][N];

void init_windy() {
    // 一位数
    g[1][0] = 0; // 0不算
    for (int i = 1; i <= 9; i++) g[1][i] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) >= 2) {
                    g[i][j] += g[i - 1][k];
                }
            }
        }
    }
}

int count_windy(int n) {
    if (n == 0) return 0;

    int len = 0;
    while (n) {
        digits[++len] = n % 10;
        n /= 10;
    }

    int res = 0;
    // 枚举最高位
    for (int i = 1; i < digits[len]; i++) {
        res += g[len][i];
    }

    // 后续位数
    for (int i = len - 1; i >= 1; i--) {
        for (int j = 0; j < digits[i]; j++) {
            if (abs(digits[i + 1] - j) >= 2) {
                res += g[i][j];
            }
        }
    }

    return res;
}

// [a, b] 区间计数
int solve(int a, int b) {
    return count(b) - count(a - 1);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    init();

    printf("%d\n", solve(a, b));

    return 0;
}
