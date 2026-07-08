// 后缀数组 (Suffix Array)
// AcWing 1328. 回文子串的最大长度 / 2316. 买卖彩票
// 将字符串的所有后缀按字典序排序，记录排序后的下标
// 时间复杂度：O(n log n)（倍增法）
// 核心应用：
//   1. 求最长公共前缀（LCP）：height 数组
//   2. 求本质不同子串数
//   3. 字符串匹配、最长重复子串等

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010;

int n;
char s[N];
// sa[i]: 排名第 i 的后缀的起始位置
// rk[i]: 起始位置为 i 的后缀的排名
// old_rk: 上一轮的排名（用于倍增）
// id: 排序用的辅助数组，cnt: 计数排序辅助
int sa[N], rk[N], old_rk[N], id[N], cnt[N];

// O(n log n) 计算后缀数组（倍增法）
// 思路：先按第一个字符排序，然后每次将排名翻倍
//       每轮排序将 (rk[i], rk[i + w]) 作为二元组排序
void get_sa() {
    int m = 128; // 字符集大小（ASCII）
    // 第一轮：按第一个字符排序（计数排序）
    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    // 倍增：每次将排名翻倍
    for (int w = 1; w < n; w *= 2) {
        memcpy(old_rk, rk, sizeof rk);
        int p = 0;
        // 按第二关键字排序（即 i + w 位置的排名）
        for (int i = n - w + 1; i <= n; i++) id[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > w) id[++p] = sa[i] - w;

        // 按第一关键字排序（计数排序）
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        // 更新排名
        p = 0;
        for (int i = 1; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] &&
                old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])
                rk[sa[i]] = p;
            else
                rk[sa[i]] = ++p;
        }
    }
}

// 高度数组 (LCP 数组)
// height[i] = LCP(sa[i], sa[i-1])，即排名相邻的两个后缀的最长公共前缀
// 利用性质：height[rk[i]] >= height[rk[i-1]] - 1
int height[N];
void get_height() {
    for (int i = 1; i <= n; i++) rk[sa[i]] = i; // 反向映射
    for (int i = 1, k = 0; i <= n; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    get_sa();
    get_height();

    // 输出后缀数组
    for (int i = 1; i <= n; i++)
        printf("%d ", sa[i]);
    printf("\n");

    // 输出高度数组
    for (int i = 1; i <= n; i++)
        printf("%d ", height[i]);
    printf("\n");

    return 0;
}
