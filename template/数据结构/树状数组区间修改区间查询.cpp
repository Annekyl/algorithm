// 树状数组 - 区间修改区间查询 (差分 + 树状数组)
// AcWing 1235. 付账问题
// 支持操作：区间修改（加）、区间查询（求和）
// 时间复杂度：修改和查询均为 O(log n)
// 核心思想：利用差分数组，将区间修改转化为两次单点修改
//   设原数组为 a[i]，差分数组为 d[i] = a[i] - a[i-1]
//   区间 [l, r] 加 v：d[l] += v, d[r+1] -= v
//   前缀和 sum[1..x] = sum(d[1..x]) * (x+1) - sum(d[i] * i)
//   需要两棵树状数组：tr1 维护 d[i]，tr2 维护 d[i] * i

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int tr1[N], tr2[N]; // tr1: 维护差分数组，tr2: 维护辅助项

int lowbit(int x) {
    return x & -x;
}

// 向树状数组 tr 的位置 x 加 v
void add(int tr[], int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

// 查询树状数组 tr 的前缀和 [1, x]
int sum(int tr[], int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

// 区间修改：将 [l, r] 内每个元素加 v
// 转化为差分数组的两次单点修改
void range_add(int l, int r, int v) {
    add(tr1, l, v);           // d[l] += v
    add(tr1, r + 1, -v);      // d[r+1] -= v
    add(tr2, l, v * (l - 1)); // tr2 维护 d[i] * (i-1)
    add(tr2, r + 1, -v * r);
}

// 区间查询：查询 [l, r] 的和
// 公式：sum[l..r] = sum(tr1, r) * r - sum(tr1, l-1) * (l-1)
//                   - sum(tr2, r) + sum(tr2, l-1)
int range_sum(int l, int r) {
    return sum(tr1, r) * r - sum(tr1, l - 1) * (l - 1) -
           sum(tr2, r) + sum(tr2, l - 1);
}

int main() {
    scanf("%d%d", &n, &m);

    // 通过区间修改构建初始数组
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        range_add(i, i, x); // 单点赋值转化为区间修改
    }

    while (m--) {
        int op, l, r, c;
        scanf("%d%d%d%d", &op, &l, &r, &c);
        if (op == 1) range_add(l, r, c);         // 区间修改
        else printf("%d\n", range_sum(l, r));     // 区间查询
    }

    return 0;
}
