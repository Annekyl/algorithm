// 线段树 (Segment Tree)
// AcWing 1275. 显示数列 / 1264. 动态求连续区间和
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int w[N];
struct Node {
    int l, r;
    int sum, add; // sum: 区间和, add: 懒标记
} tr[N * 4];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (tr[u].add) {
        auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        left.sum += (left.r - left.l + 1) * root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        left.add += root.add;
        right.add += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if (l == r) tr[u].sum = w[l];
    else {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void update(int u, int l, int r, int v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) update(u << 1, l, r, v);
    if (r > mid) update(u << 1 | 1, l, r, v);
    pushup(u);
}

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
