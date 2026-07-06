// ST表 (Sparse Table)
// AcWing 1262. 鱼塘钓鱼 / 1270. 混合牛奶
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010, LOG = 18;

int n, q;
int w[N];
int f[N][LOG]; // f[i][j]表示从i开始长度为2^j的区间的最大值

void build() {
    for (int i = 1; i <= n; i++) f[i][0] = w[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

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
