// Z函数 (扩展KMP)
// AcWing 159. 团伙 / 2816. 链表相交
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000010;

char s[N];
int z[N], n;

// O(n)计算Z函数
void get_z() {
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

// Z函数用于字符串匹配
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
