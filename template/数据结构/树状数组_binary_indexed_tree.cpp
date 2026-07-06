// 树状数组 (Binary Indexed Tree / Fenwick Tree)
// AcWing 1264. 动态求连续区间和 / 1235. 付账问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int tr[N]; // 树状数组

// lowbit操作
int lowbit(int x) {
    return x & -x;
}

// 单点修改
void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

// 前缀和查询
int sum(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

// 区间查询
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

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(i, x);
    }

    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) add(a, b);
        else printf("%d\n", range_sum(a, b));
    }

    return 0;
}
