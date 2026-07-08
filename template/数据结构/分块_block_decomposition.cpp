// 分块 (Block Decomposition)
// AcWing 1269. 合并区间 / 912. 求逆序对
// 一种介于暴力和高级数据结构之间的折中方法
// 核心思想：将数组分成若干块，块内维护整体信息，块间暴力处理
// 时间复杂度：O(sqrt(n))，通过调整块大小可以平衡时间
// 适用场景：修改和查询操作较复杂，难以用树状数组/线段树实现时

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n, m, len, cnt; // len: 块大小, cnt: 块数量
int w[N], blo[N], add[N]; // blo[i]: 位置 i 所属的块, add[i]: 块的懒标记

// 构建分块
// 块大小取 sqrt(n)，使得块内和块间操作复杂度均为 O(sqrt(n))
void build() {
    len = sqrt(n);
    cnt = (n - 1) / len + 1;
    // 预处理每个位置所属的块
    for (int i = 1; i <= n; i++) blo[i] = (i - 1) / len + 1;
    // 计算每块的初始和
    for (int i = 1; i <= n; i++) add[blo[i]] += w[i];
}

// 区间查询：查询 [l, r] 的和
// 分三种情况处理：
// 1. l 和 r 在同一块内：暴力遍历
// 2. l 所在块的剩余部分：暴力遍历
// 3. r 所在块的前部分：暴力遍历
// 4. 中间的整块：直接用块的和
int query(int l, int r) {
    int res = 0;
    if (blo[l] == blo[r]) {
        // l 和 r 在同一块内，暴力遍历
        for (int i = l; i <= r; i++) res += w[i];
        return res;
    }
    // 处理 l 所在块的剩余部分
    for (int i = l; i <= blo[l] * len; i++) res += w[i];
    // 处理 r 所在块的前部分
    for (int i = (blo[r] - 1) * len + 1; i <= r; i++) res += w[i];
    // 处理中间的整块
    for (int i = blo[l] + 1; i < blo[r]; i++) res += add[i];
    return res;
}

// 区间修改：将 [l, r] 内每个元素加 v
// 分三种情况处理：
// 1. l 和 r 在同一块内：暴力修改
// 2. l 所在块的剩余部分：暴力修改
// 3. r 所在块的前部分：暴力修改
// 4. 中间的整块：更新块的懒标记
void update(int l, int r, int v) {
    if (blo[l] == blo[r]) {
        // l 和 r 在同一块内，暴力修改
        for (int i = l; i <= r; i++) w[i] += v;
        add[blo[l]] += v * (r - l + 1);
        return;
    }
    // 处理 l 所在块的剩余部分
    for (int i = l; i <= blo[l] * len; i++) w[i] += v;
    // 处理 r 所在块的前部分
    for (int i = (blo[r] - 1) * len + 1; i <= r; i++) w[i] += v;
    // 处理中间的整块：只更新懒标记
    for (int i = blo[l] + 1; i < blo[r]; i++) add[i] += v * len;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    build();

    scanf("%d", &m);
    while (m--) {
        char op[2];
        int l, r, c;
        scanf("%s%d%d%d", op, &l, &r, &c);
        if (op[0] == 'C') update(l, r, c);
        else printf("%d\n", query(l, r));
    }

    return 0;
}
