// 数位DP (Digit DP)
// AcWing 1081. 度的数量 / 1082. 数字游戏 / 1083. windy数
// 用于解决与数位相关的问题，如：
//   1. 统计 [l, r] 中满足某种条件的数的个数
//   2. 求 [l, r] 中满足条件的最大/最小值
// 时间复杂度：O(位数 * 状态数)
// 核心思想：
//   1. 将数字按位拆分
//   2. 逐位枚举，利用预处理加速
//   3. 通常用 f(upper) - f(lower-1) 求区间答案

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int digits[N];      // 存储数字的每一位
int f[N][N];         // f[i][j]: 长度为 i，最高位为 j 的方案数

// 预处理 f 数组
// f[i][j] = 长度为 i，最高位为 j 的满足条件的数的个数
void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!i) f[i][j] = 1; // 长度为 0，只有空串
            else
                for (int k = 0; k < N; k++)
                    f[i][j] += f[i - 1][k]; // 枚举下一位
}

// 数字计数：统计 [0, n] 中满足条件的数的个数
// 方法：逐位枚举，利用预处理的 f 数组
int count(int n) {
    if (n == 0) return 1;

    // 拆分数字的每一位
    int len = 0;
    while (n) {
        digits[++len] = n % 10;
        n /= 10;
    }

    int res = 0;
    // 从最高位开始枚举
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < digits[i]; j++) {
            res += f[i][j]; // 长度为 i，最高位为 j 的数
        }
    }

    return res;
}

// 计算不含前导零的数字个数
// 最高位不能为 0
int count_no_leading_zero(int n) {
    if (n == 0) return 0;

    int len = 0;
    while (n) {
        digits[++len] = n % 10;
        n /= 10;
    }

    int res = 0;
    // 最高位不能为 0
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

// ==================== Windy数 ====================
// Windy数：相邻数字差至少为 2 的正整数
// g[i][j]: 长度为 i，最高位为 j 的 Windy 数个数
int g[N][N];

void init_windy() {
    // 一位数
    g[1][0] = 0; // 0 不算
    for (int i = 1; i <= 9; i++) g[1][i] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) >= 2) { // 相邻数字差 >= 2
                    g[i][j] += g[i - 1][k];
                }
            }
        }
    }
}

// 统计 [0, n] 中 Windy 数的个数
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

// 区间计数：[a, b] 中满足条件的数的个数
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
