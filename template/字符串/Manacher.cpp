// Manacher算法
// AcWing 158. 回文子串的最大长度
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000010;

char s[N], t[N];
int d[N], n, m;

// 预处理字符串 (在字符间插入分隔符)
void preprocess() {
    t[m++] = '$';
    t[m++] = '#';
    for (int i = 0; i < n; i++) {
        t[m++] = s[i];
        t[m++] = '#';
    }
    t[m++] = '^';
}

// Manacher算法求回文半径
void manacher() {
    for (int i = 1, center = 0, right = 0; i < m - 1; i++) {
        if (i < right)
            d[i] = min(d[2 * center - i], right - i);
        while (t[i - d[i]] == t[i + d[i]])
            d[i]++;
        if (i + d[i] > right) {
            center = i;
            right = i + d[i];
        }
    }
}

// 获取最长回文子串长度
int get_longest_palindrome() {
    int res = 0;
    for (int i = 1; i < m - 1; i++) {
        res = max(res, d[i] - 1);
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

    int start = (center - max_len) / 2;
    for (int i = start; i < start + max_len; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// 统计所有回文子串数量
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
