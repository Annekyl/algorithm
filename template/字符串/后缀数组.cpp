// 后缀数组 (Suffix Array)
// AcWing 1328. 回文子串的最大长度 / 2316. 买卖彩票
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010;

int n;
char s[N];
int sa[N], rk[N], old_rk[N], id[N], cnt[N];

// O(n)计算后缀数组 (倍增法)
void get_sa() {
    int m = 128;
    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1; w < n; w *= 2) {
        memcpy(old_rk, rk, sizeof rk);
        int p = 0;
        for (int i = n - w + 1; i <= n; i++) id[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > w) id[++p] = sa[i] - w;

        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

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

// 高度数组 (LCP数组)
int height[N];
void get_height() {
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
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
