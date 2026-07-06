// 分块 (Block Decomposition)
// AcWing 1269. 合并区间 / 912. 求逆序对
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n, m, len, cnt;
int w[N], blo[N], add[N];

void build() {
    len = sqrt(n);
    cnt = (n - 1) / len + 1;
    for (int i = 1; i <= n; i++) blo[i] = (i - 1) / len + 1;
    for (int i = 1; i <= n; i++) add[blo[i]] += w[i];
}

int query(int l, int r) {
    int res = 0;
    if (blo[l] == blo[r]) {
        for (int i = l; i <= r; i++) res += w[i];
        return res;
    }
    for (int i = l; i <= blo[l] * len; i++) res += w[i];
    for (int i = (blo[r] - 1) * len + 1; i <= r; i++) res += w[i];
    for (int i = blo[l] + 1; i < blo[r]; i++) res += add[i];
    return res;
}

void update(int l, int r, int v) {
    if (blo[l] == blo[r]) {
        for (int i = l; i <= r; i++) w[i] += v;
        add[blo[l]] += v * (r - l + 1);
        return;
    }
    for (int i = l; i <= blo[l] * len; i++) w[i] += v;
    for (int i = (blo[r] - 1) * len + 1; i <= r; i++) w[i] += v;
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
