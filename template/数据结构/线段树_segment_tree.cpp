// 线段树 (Segment Tree)
// AcWing 1275. 显示数列 / 1264. 动态求连续区间和
// 支持操作：区间修改（加）、区间查询（求和）
// 时间复杂度：修改和查询均为 O(log n)
// 空间复杂度：O(n)，需要 4n 的数组空间
// 核心思想：用二叉树维护区间信息，利用懒标记实现区间修改的延迟下传

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int w[N];
struct Node {
    int l, r;    // 区间左右端点
    int sum, add; // sum: 区间和, add: 懒标记（延迟修改）
} tr[N * 4]; // 开 4 倍空间，防止越界

// 上传：用子节点信息更新父节点
void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

// 下传：将懒标记传递给子节点
// 当需要访问子节点时，才将父节点的修改下传
void pushdown(int u) {
    if (tr[u].add) {
        auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        // 更新子节点的 sum 和 add
        left.sum += (left.r - left.l + 1) * root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        left.add += root.add;
        right.add += root.add;
        root.add = 0; // 清除懒标记
    }
}

// 建树：递归构建线段树
// u: 当前节点编号，[l, r]: 维护的区间
void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if (l == r) tr[u].sum = w[l]; // 叶子节点
    else {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);       // 左子树
        build(u << 1 | 1, mid + 1, r); // 右子树
        pushup(u);                    // 用子节点更新当前节点
    }
}

// 区间修改：将 [l, r] 内每个元素加 v
// 如果当前区间被完全包含，直接修改并打上懒标记
// 否则下传懒标记，递归修改子区间，最后上传
void update(int u, int l, int r, int v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
        return;
    }
    pushdown(u); // 先下传懒标记
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) update(u << 1, l, r, v);
    if (r > mid) update(u << 1 | 1, l, r, v);
    pushup(u); // 用子节点更新当前节点
}

// 区间查询：查询 [l, r] 的和
// 如果当前区间被完全包含，直接返回
// 否则下传懒标记，递归查询子区间
int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    build(1, 1, n);

    while (m--) {
        char op[2];
        int a, b, c;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'Q') {
            printf("%d\n", query(1, a, b));
        } else {
            scanf("%d", &c);
            update(1, a, b, c);
        }
    }

    return 0;
}
