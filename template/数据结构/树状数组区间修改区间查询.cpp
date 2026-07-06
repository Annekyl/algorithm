// 树状数组 - 区间修改区间查询
// AcWing 1235. 付账问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int tr1[N], tr2[N]; // tr1维护单点加, tr2维护辅助

int lowbit(int x) {
    return x & -x;
}

void add(int tr[], int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int sum(int tr[], int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

void range_add(int l, int r, int v) {
    add(tr1, l, v);
    add(tr1, r + 1, -v);
    add(tr2, l, v * (l - 1));
    add(tr2, r + 1, -v * r);
}

int range_sum(int l, int r) {
    return sum(tr1, r) * r - sum(tr1, l - 1) * (l - 1) -
           sum(tr2, r) + sum(tr2, l - 1);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        range_add(i, i, x);
    }

    while (m--) {
        int op, l, r, c;
        scanf("%d%d%d%d", &op, &l, &r, &c);
        if (op == 1) range_add(l, r, c);
        else printf("%d\n", range_sum(l, r));
    }

    return 0;
}
