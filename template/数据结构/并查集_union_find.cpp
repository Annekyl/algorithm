// 并查集 (Union-Find)
// AcWing 876. 快速幂求逆元 / 837. 连通块中点的数量
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int p[N], d[N], sz[N]; // d: 秩, sz: 连通块大小

// 查找根节点 + 路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化并查集
void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

// 合并两个集合 (按秩合并)
void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (d[a] < d[b]) swap(a, b);
        p[b] = a;
        if (d[a] == d[b]) d[a]++;
        sz[a] += sz[b];
    }
}

// 判断是否在同一集合
bool same(int a, int b) {
    return find(a) == find(b);
}

int main() {
    scanf("%d%d", &n, &m);
    init();

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'Q') {
            if (same(a, b)) printf("Yes\n");
            else printf("No\n");
        } else {
            merge(a, b);
        }
    }

    return 0;
}
