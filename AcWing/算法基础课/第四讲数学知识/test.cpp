#include <algorithm>
#include <iostream>

using namespace std;

const int N = 110; // 定义矩阵的最大大小

int n;       // 方程的数量（也是未知数的数量）
int a[N][N]; // 增广矩阵，a[i][j]表示第i个方程的第j个系数，a[i][n]表示常数项

// 高斯消元法求解异或线性方程组
int gauss() {
    int c, r; // c表示当前列，r表示当前行
    for (c = 0, r = 0; c < n; c++) {
        // 找到当前列中第一个非零的行
        int t = r;
        for (int i = r; i < n; i++) {
            if (a[i][c]) {
                t = i;
                break;
            }
        }

        // 如果当前列全为零，跳过该列
        if (!a[t][c])
            continue;

        // 将主元行交换到当前行r
        for (int i = c; i <= n; i++)
            swap(a[r][i], a[t][i]);

        // 用主元行消去下面所有行的当前列的非零元素
        for (int i = r + 1; i < n; i++) {
            if (a[i][c]) {
                for (int j = n; j >= c; j--) {
                    a[i][j] ^= a[r][j]; // 异或操作
                }
            }
        }

        r++; // 移动到下一行
    }

    // 判断解的情况
    if (r < n) {
        // 检查是否有矛盾（0 = 1）
        for (int i = r; i < n; i++) {
            if (a[i][n]) {
                return 2; // 无解
            }
        }
        return 1; // 多解
    }

    // 回代求解唯一解
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] ^= a[i][j] * a[j][n]; // 异或操作
        }
    }

    return 0; // 唯一解
}

int main() {
    cin >> n; // 输入方程的数量

    // 输入增广矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    // 调用高斯消元法求解
    int t = gauss();

    // 输出结果
    if (t == 0) {
        // 输出唯一解
        for (int i = 0; i < n; i++) {
            cout << a[i][n] << endl;
        }
    } else if (t == 1) {
        puts("Multiple sets of solutions"); // 多解
    } else {
        puts("No solution"); // 无解
    }

    return 0;
}