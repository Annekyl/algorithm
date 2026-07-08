// 树状数组 (Binary Indexed Tree / Fenwick Tree)
// AcWing 1264. 动态求连续区间和 / 1235. 付账问题
// 支持操作：单点修改、区间查询（前缀和）
// 时间复杂度：修改和查询均为 O(log n)
// 空间复杂度：O(n)
// 核心思想：利用 lowbit 操作将数组组织成树形结构，高效维护前缀和
// lowbit(x) = x & (-x)，即 x 的二进制表示中最低位的 1 及其后面的 0

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int tr[N]; // 树状数组

// lowbit 操作：取 x 的二进制表示中最低位的 1 及其后面的 0
// 例如：lowbit(12) = lowbit(1100) = 100 = 4
int lowbit(int x) {
    return x & -x;
}

// 单点修改：将位置 x 的值加 v
// 从 x 开始，沿着树向上更新所有包含 x 的节点
// 每次跳到 x + lowbit(x)
void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

// 前缀和查询：查询 [1, x] 的和
// 从 x 开始，沿着树向下累加
// 每次跳到 x - lowbit(x)
int sum(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

// 区间查询：查询 [l, r] 的和
// 利用前缀和差分：sum(l, r) = sum(r) - sum(l - 1)
int range_sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

// 初始化
void init() {
    memset(tr, 0, sizeof tr);
}

int main() {
    scanf("%d%d", &n, &m);
    init();

    // 逐个插入构建树状数组
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(i, x);
    }

    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) add(a, b);          // 单点修改
        else printf("%d\n", range_sum(a, b)); // 区间查询
    }

    return 0;
}
