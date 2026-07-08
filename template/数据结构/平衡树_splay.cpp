// 平衡树 (Splay)
// AcWing 104. 仓库选址 / 153. 普通平衡树
// 一种自平衡二叉搜索树，支持操作：
//   1. 插入元素
//   2. 删除元素
//   3. 查询排名（比当前元素小的个数 + 1）
//   4. 按排名查询元素值
//   5. 查询前驱（小于当前元素的最大值）
//   6. 查询后继（大于当前元素的最小值）
// 时间复杂度：所有操作均为 O(log n)（均摊）
// 核心操作：splay(x) 将节点 x 旋转到根节点

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 1e9;

int n, m, root, idx;
// tr[x][0]: 左子节点, tr[x][1]: 右子节点
// parent[x]: 父节点, cnt[x]: 值 x 出现次数, size[x]: 子树大小
int tr[N][2], parent[N], cnt[N], size[N], key[N];

// 上传：更新子树大小
void pushup(int x) {
    size[x] = size[tr[x][0]] + size[tr[x][1]] + cnt[x];
}

// 判断 x 是父节点的左子节点还是右子节点
bool get(int x) {
    return tr[parent[x]][1] == x;
}

// 旋转操作：将 x 向上旋转一层
// 核心：维护 BST 性质，同时更新子树大小
void rotate(int x) {
    int y = parent[x], z = parent[y];
    int k = get(x);
    // 旋转：将 x 的子节点 y 的另一侧子树挂到 x 上
    tr[y][k] = tr[x][k ^ 1];
    parent[tr[x][k ^ 1]] = y;
    tr[x][k ^ 1] = y;
    parent[y] = x;
    // 将 x 挂到 z 上
    tr[z][get(y)] = x;
    parent[x] = z;
    pushup(y);
    pushup(x);
}

// Splay 操作：将 x 旋转到 k 的子节点位置
// 当 k = 0 时，旋转到根节点
// 使用双旋和单旋的组合，均摊 O(log n)
void splay(int x, int k) {
    while (parent[x] != k) {
        int y = parent[x], z = parent[y];
        if (z != k) {
            if (get(x) == get(y)) rotate(y); // 同侧：先旋转父节点
            else rotate(x);                    // 异侧：先旋转自身
        }
        rotate(x);
    }
    if (!k) root = x;
}

// 插入元素 v
// 先按 BST 性质查找位置，然后 splay 到根
void insert(int v) {
    int x = root, p = 0;
    while (x && key[x] != v) {
        p = x;
        size[x]++;
        x = tr[x][v > key[x]];
    }
    if (x) cnt[x]++; // 已存在，计数加1
    else {
        x = ++idx;
        key[x] = v;
        cnt[x] = 1;
        size[x] = 1;
        parent[x] = p;
        tr[p][v > key[p]] = x;
    }
    splay(x, 0); // 旋转到根
}

// 获取 v 的排名（比 v 小的元素个数 + 1）
int get_rank(int v) {
    int x = root, res = 0;
    while (x) {
        if (key[x] < v) {
            res += size[tr[x][0]] + cnt[x];
            x = tr[x][1];
        } else {
            x = tr[x][0];
        }
    }
    return res + 1;
}

// 按排名查询元素值（第 rank 小的元素）
int get_val(int rank) {
    int x = root;
    while (x) {
        if (size[tr[x][0]] >= rank) {
            x = tr[x][0];
        } else if (size[tr[x][0]] + cnt[x] >= rank) {
            return key[x];
        } else {
            rank -= size[tr[x][0]] + cnt[x];
            x = tr[x][1];
        }
    }
    return -1;
}

// 查询 v 的前驱（小于 v 的最大元素）
int get_prev(int v) {
    int x = root, res = -INF;
    while (x) {
        if (key[x] < v) {
            res = key[x];
            x = tr[x][1];
        } else {
            x = tr[x][0];
        }
    }
    return res;
}

// 查询 v 的后继（大于 v 的最小元素）
int get_next(int v) {
    int x = root, res = INF;
    while (x) {
        if (key[x] > v) {
            res = key[x];
            x = tr[x][0];
        } else {
            x = tr[x][1];
        }
    }
    return res;
}

// 删除元素 v
// 方法：将 v 的前驱和后继 splay 到根，然后删除中间的节点
void remove(int v) {
    int r1 = get_rank(v);
    int r2 = get_rank(v + 1);
    splay(get_val(r1), 0);  // 将 v 的前驱旋转到根
    splay(get_val(r2), root); // 将 v 的后继旋转到根的右子节点
    int del = tr[root][1][0]; // 要删除的节点
    if (cnt[del] > 1) {
        cnt[del]--;
        splay(del, 0);
    } else {
        tr[root][1][0] = 0;
        splay(root, 0);
    }
}

int main() {
    // 插入哨兵节点，避免边界判断
    insert(-INF);
    insert(INF);

    scanf("%d", &n);
    while (n--) {
        int op, x;
        scanf("%d%d", &op, &x);
        switch (op) {
            case 1: insert(x); break;                              // 插入
            case 2: remove(x); break;                              // 删除
            case 3: printf("%d\n", get_rank(x)); break;            // 排名
            case 4: printf("%d\n", get_val(x + 1)); break;         // 按排名查值
            case 5: printf("%d\n", get_prev(x)); break;            // 前驱
            case 6: printf("%d\n", get_next(x)); break;            // 后继
        }
    }

    return 0;
}
