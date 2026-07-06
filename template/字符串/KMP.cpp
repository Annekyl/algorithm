// KMP算法
// AcWing 831. KMP字符串
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int ne[N]; // next数组 / 失配函数

// 构建next数组
void build_next() {
    ne[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j++;
        ne[i] = j;
    }
}

// KMP匹配
void kmp() {
    build_next();
    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && p[j + 1] != s[i]) j = ne[j];
        if (p[j + 1] == s[i]) j++;
        if (j == n - 1) {
            printf("%d ", i - n + 1);
            j = ne[j];
        }
    }
}

// 字符串匹配 (返回所有匹配位置)
void find_all_occurrences() {
    build_next();
    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && p[j + 1] != s[i]) j = ne[j];
        if (p[j + 1] == s[i]) j++;
        if (j == n - 1) {
            printf("%d\n", i - n + 1);
            j = ne[j];
        }
    }
}

// 最小循环节
int get_min_cycle() {
    build_next();
    int len = n - ne[n - 1] - 1;
    if (n % len == 0) return len;
    return n;
}

// KMP计数 (模式串在文本串中出现次数)
int count_occurrences() {
    build_next();
    int cnt = 0;
    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && p[j + 1] != s[i]) j = ne[j];
        if (p[j + 1] == s[i]) j++;
        if (j == n - 1) {
            cnt++;
            j = ne[j];
        }
    }
    return cnt;
}

int main() {
    scanf("%d%s%s", &n, p, &m, s);

    kmp();

    return 0;
}
