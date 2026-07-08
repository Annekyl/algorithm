// 并查集 (Union-Find / Disjoint Set Union)
// AcWing 876. 快速幂求逆元 / 837. 连通块中点的数量
// 支持操作：合并两个集合、查询两个元素是否在同一集合
// 时间复杂度：近似 O(1)，使用路径压缩和按秩合并
// 核心思想：每个集合用一棵树表示，根节点代表集合编号
// 优化手段：
//   1. 路径压缩：查找时将路径上的节点直接连接到根
//   2. 按秩合并：合并时将矮树接到高树下，保持树平衡

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int p[N], d[N], sz[N]; // p: 父节点, d: 秩(树高上界), sz: 连通块大小

// 查找根节点 + 路径压缩
// 递归查找，同时将路径上所有节点直接指向根
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化并查集：每个元素单独构成一个集合
void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

// 合并两个集合 (按秩合并)
// 将矮树接到高树下，保持树平衡
// 如果两棵树高度相同，合并后高度加1
void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (d[a] < d[b]) swap(a, b); // 保证 a 的秩 >= b 的秩
        p[b] = a;
        if (d[a] == d[b]) d[a]++;    // 秩相同时，合并后秩加1
        sz[a] += sz[b];              // 更新连通块大小
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
