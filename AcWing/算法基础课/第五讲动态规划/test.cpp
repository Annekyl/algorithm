#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

/*
 * 计算数字n的各位数字，从低位到高位存储
 */
int get(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i--) // 从高位到低位拼接数字
        res = res * 10 + num[i];
    return res;
}

/*
 * 计算10的x次幂
 */
int power10(int x) {
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

/*
 * 计算从1到n中数字x出现的次数
 * 使用数位DP的思想，按位分析
 */
int count(int n, int x) {
    if (!n)
        return 0; // 如果n为0，直接返回0

    vector<int> num; // 存储n的各位数字（逆序：低位在前）
    while (n) {
        num.push_back(n % 10); // 取最低位
        n /= 10;               // 去掉最低位
    }
    n = num.size(); // n现在表示数字的位数

    int res = 0; // 结果

    // 从最高位开始遍历（如果x=0，则从第二位开始，因为最高位不能是0）
    for (int i = n - 1 - !x; i >= 0; i--) {
        // 第一部分：计算当前位之前的数字组合
        if (i < n - 1) { // 不是最高位时
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x) // 如果统计的是0，需要减去以0开头的情况
                res -= power10(i);
        }

        // 第二部分：根据当前位与x的关系计算
        if (num[i] == x) // 当前位等于x
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x) // 当前位大于x
            res += power10(i);
        // 当前位小于x时，这部分为0
    }

    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a) { // 循环读取输入，直到a为0
        if (a > b)
            swap(a, b); // 确保a <= b

        // 计算每个数字在[a, b]区间内出现的次数
        // 使用前缀和思想：count(b) - count(a-1)
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }

    return 0;
}