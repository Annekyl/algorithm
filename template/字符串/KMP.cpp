// KMP算法 (Knuth-Morris-Pratt Algorithm)
// AcWing 831. KMP字符串
// 用于字符串模式匹配，时间复杂度 O(n + m)
// 核心思想：利用已匹配的信息避免重复比较
// next 数组（失配函数）：next[i] 表示 p[0..i] 的最长相等前后缀长度
// 当 p[j+1] 匹配失败时，跳转到 next[j] 继续匹配

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int ne[N]; // next 数组 / 失配函数

// 构建 next 数组（也称 fail 数组或 prefix function）
// ne[i] = p[0..i] 的最长相等前后缀的长度
// 利用已有的 next 信息递推，避免暴力
void build_next() {
    ne[0] = -1; // 约定 ne[0] = -1，方便处理边界
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j]; // 回退
        if (p[j + 1] == p[i]) j++;
        ne[i] = j;
    }
}

// KMP 匹配：在文本串 s 中查找模式串 p 的所有出现位置
// 当匹配失败时，利用 next 数组跳转，避免从头开始
void kmp() {
    build_next();
    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && p[j + 1] != s[i]) j = ne[j]; // 回退
        if (p[j + 1] == s[i]) j++;
        if (j == n - 1) { // 完整匹配
            printf("%d ", i - n + 1);
            j = ne[j]; // 继续寻找下一个匹配
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
// 若 n % (n - ne[n-1] - 1) == 0，则字符串由 (n - ne[n-1] - 1) 长度的子串循环构成
int get_min_cycle() {
    build_next();
    int len = n - ne[n - 1] - 1;
    if (n % len == 0) return len;
    return n;
}

// KMP 计数：统计模式串在文本串中出现次数
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
