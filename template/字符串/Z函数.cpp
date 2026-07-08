// Z函数 (Z-Function / 扩展KMP)
// AcWing 159. 团伙 / 2816. 链表相交
// 对于字符串 s，z[i] 表示 s 和 s[i..n-1] 的最长公共前缀长度
// z[0] = n（约定）
// 时间复杂度：O(n)
// 核心思想：利用已计算的 z 值加速后续计算（类似 KMP 的思想）
// 应用：字符串匹配、计算本质不同子串数

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000010;

char s[N];
int z[N], n;

// O(n) 计算 Z 函数
// 维护区间 [l, r] 表示以 l 开头的与 s[0..] 的最长公共前缀区间
void get_z() {
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r)
            z[i] = min(z[i - l], r - i); // 利用已计算的 z 值
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++; // 暴力扩展
        if (i + z[i] > r) {
            l = i;
            r = i + z[i]; // 更新 [l, r]
        }
    }
}

// Z 函数用于字符串匹配
// 拼接 pattern + '#' + text，计算 Z 函数
// 若 z[i] >= |pattern|，则 text[i - |pattern| - 1] 处匹配
void find_occurrences(char *pattern, char *text) {
    int plen = strlen(pattern);
    int tlen = strlen(text);

    // 拼接字符串
    char concat[N];
    sprintf(concat, "%s#%s", pattern, text);

    n = strlen(concat);
    strcpy(s, concat);
    get_z();

    // 查找匹配
    for (int i = plen + 1; i < n; i++) {
        if (z[i] >= plen) {
            printf("%d\n", i - plen - 1);
        }
    }
}

// 计算本质不同子串数
// 利用 Z 函数：总子串数 n*(n+1)/2 减去所有 z[i] 的和
long long count_distinct_substrings() {
    get_z();
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += z[i];
    }
    return res - (long long)n * (n - 1) / 2;
}

int main() {
    scanf("%s", s);
    n = strlen(s);

    get_z();

    for (int i = 0; i < n; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    return 0;
}
