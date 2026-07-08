// ST表 (Sparse Table)
// AcWing 1262. 鱼塘钓鱼 / 1270. 混合牛奶
// 用于解决静态区间最值查询问题（不支持修改）
// 时间复杂度：预处理 O(n log n)，查询 O(1)
// 空间复杂度：O(n log n)
// 核心思想：倍增法预处理，利用区间可重复覆盖的性质
//   f[i][j] 表示从 i 开始长度为 2^j 的区间的最大值
//   查询 [l, r] 时，取 k = log2(r - l + 1)
//   则 max(l, r) = max(f[l][k], f[r - 2^k + 1][k])

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010, LOG = 18;

int n, q;
int w[N];
int f[N][LOG]; // f[i][j]: 从 i 开始长度为 2^j 的区间的最大值

// 预处理 ST 表
// 第一层：f[i][0] = w[i]（长度为 1 的区间）
// 后续层：f[i][j] = max(f[i][j-1], f[i + 2^(j-1)][j-1])
void build() {
    for (int i = 1; i <= n; i++) f[i][0] = w[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

// 查询 [l, r] 的最大值
// 利用 log2 预计算长度，取两个重叠区间的最大值
int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    build();

    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }

    return 0;
}
