#include <algorithm>
#include <iostream>

using namespace std;

// 使用unsigned long long类型，可以利用自然溢出特性（相当于模2^64）
typedef unsigned long long ULL;

const int N = 100010; // 数组最大长度
const int P = 131;    // 哈希算法的进制基数（通常选择131或13331这样的质数）

int n, m;    // n: 字符串长度, m: 查询次数
char str[N]; // 存储输入的字符串，从索引1开始
ULL h[N];    // 前缀哈希数组，h[i]表示前i个字符的哈希值
ULL p[N];    // 存储P的幂次方，p[i] = P^i

// 计算子串str[l...r]的哈希值
ULL get(int l, int r) {
    // 哈希计算公式：h[r] - h[l-1] * p[r-l+1]
    // 原理：将前l-1个字符的哈希值左移到与前r个字符对齐的位置，然后相减
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    // 读取字符串长度和查询次数
    scanf("%d%d", &n, &m);
    // 读取字符串，从str[1]开始存储（索引从1开始）
    scanf("%s", str + 1);

    // 初始化p[0] = P^0 = 1
    p[0] = 1;

    // 预处理前缀哈希数组和幂次数组
    for (int i = 1; i <= n; i++) {
        // 计算前i个字符的哈希值：h[i] = h[i-1] * P + str[i]
        // 相当于将前i-1个字符的哈希值左移一位，然后加上当前字符
        h[i] = h[i - 1] * P + str[i];

        // 计算P的i次方，用于后续哈希计算
        p[i] = p[i - 1] * P;
    }

    // 处理每个查询
    while (m--) {
        int l1, r1, l2, r2;
        // 读取两个区间：[l1, r1] 和 [l2, r2]
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        // 比较两个子串的哈希值
        if (get(l1, r1) == get(l2, r2))
            puts("Yes"); // 哈希值相同，子串相同
        else
            puts("No"); // 哈希值不同，子串不同
    }

    return 0;
}