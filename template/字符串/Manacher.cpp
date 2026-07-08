// Manacher算法 (马拉车算法)
// AcWing 158. 回文子串的最大长度
// 在 O(n) 时间内找出字符串中所有回文子串的最长长度
// 核心思想：利用回文的对称性，避免重复计算
// 预处理：在字符间插入分隔符（如 '#'），统一处理奇偶长度的回文
// d[i] 表示以位置 i 为中心的回文半径（不含中心）

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000010;

char s[N], t[N]; // s: 原串, t: 预处理后的串
int d[N], n, m;  // d[i]: t 中以 i 为中心的回文半径

// 预处理字符串（在字符间插入分隔符）
// 例如：abc -> $#a#b#c#$
// 奇数长度回文：aba -> $#a#b#a#$
// 偶数长度回文：abba -> $#a#b#b#a#$
void preprocess() {
    t[m++] = '$'; // 起始哨兵
    t[m++] = '#';
    for (int i = 0; i < n; i++) {
        t[m++] = s[i];
        t[m++] = '#';
    }
    t[m++] = '^'; // 结束哨兵
}

// Manacher 算法求回文半径
// 维护 center 和 right，分别表示当前最右回文的中心和右边界
// 利用对称性：d[i] >= min(d[2*center - i], right - i)
void manacher() {
    for (int i = 1, center = 0, right = 0; i < m - 1; i++) {
        if (i < right)
            d[i] = min(d[2 * center - i], right - i); // 利用对称性
        while (t[i - d[i]] == t[i + d[i]]) d[i]++;     // 暴力扩展
        if (i + d[i] > right) {
            center = i;
            right = i + d[i]; // 更新最右回文
        }
    }
}

// 获取最长回文子串长度
int get_longest_palindrome() {
    int res = 0;
    for (int i = 1; i < m - 1; i++) {
        res = max(res, d[i] - 1); // d[i] - 1 即为原串中的回文长度
    }
    return res;
}

// 获取最长回文子串
void get_longest_palindrome_string() {
    int max_len = 0, center = 0;
    for (int i = 1; i < m - 1; i++) {
        if (d[i] - 1 > max_len) {
            max_len = d[i] - 1;
            center = i;
        }
    }

    // 计算原串中的起始位置
    int start = (center - max_len) / 2;
    for (int i = start; i < start + max_len; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// 统计所有回文子串数量
// 奇数长度回文贡献 (d[i] - 1) / 2 个
// 偶数长度回文贡献 d[i] / 2 个
long long count_palindromes() {
    long long res = 0;
    for (int i = 1; i < m - 1; i++) {
        res += (d[i] - 1) / 2;
        res += (d[i]) / 2;
    }
    return res;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    m = 0;

    preprocess();
    manacher();

    printf("%d\n", get_longest_palindrome());

    return 0;
}
