// Link-Cut Tree (LCT / 动态树)
// AcWing 396. 猴子王国
// 一种动态树数据结构，支持：
//   1. link(x, y): 连接 x 和 y
//   2. cut(x, y): 断开 x 和 y 的边
//   3. findroot(x): 查询 x 所在树的根
//   4. split(x, y): 将 x 到 y 的路径提取为一条链
// 时间复杂度：所有操作均为 O(log n)（均摊）
// 核心思想：将树分解为若干条链，用 Splay 维护每条链
// 通过 access 操作将任意节点到根的路径变为一条 preferred path

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
struct Node {
    int s[2], p, v; // s[0]: 左子, s[1]: 右子, p: 父节点, v: 值
    int rev;        // rev: 翻转标记
} tr[N];

int stk[N]; // 辅助栈，用于下传标记

// 判断 x 是否为 Splay 的根节点
bool isroot(int x) {
    int p = tr[x].p;
    return tr[p].s[0] != x && tr[p].s[1] != x;
}

// 上传：更新子树信息（本题为空操作，可根据需要扩展）
void pushup(int x) {
}

// 翻转标记：交换左右子树
void pushrev(int x) {
    swap(tr[x].s[0], tr[x].s[1]);
    tr[x].rev ^= 1;
}

// 下传标记：将翻转标记传递给子节点
void pushdown(int x) {
    if (tr[x].rev) {
        if (tr[x].s[0]) pushrev(tr[x].s[0]);
        if (tr[x].s[1]) pushrev(tr[x].s[1]);
        tr[x].rev = 0;
    }
}

// 旋转操作：将 x 向上旋转一层
void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    if (!isroot(y)) tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    if (tr[x].s[k ^ 1]) tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y;
    tr[y].p = x;
}

// Splay 操作：将 x 旋转到所在辅助树的根
// 先下传从 x 到根路径上的所有标记
void splay(int x) {
    int top = 0, y = x;
    stk[++top] = y;
    while (!isroot(y)) {
        y = tr[y].p;
        stk[++top] = y;
    }
    while (top) pushdown(stk[top--]); // 下传标记

    while (!isroot(x)) {
        y = tr[x].p;
        if (!isroot(y)) {
            if ((tr[y].s[1] == x) ^ (tr[tr[y].p].s[1] == y))
                rotate(x); // 异侧：先旋转 x
            else
                rotate(y); // 同侧：先旋转 y
        }
        rotate(x);
    }
}

// Access 操作：将 x 到根的路径变为一条 preferred path
// 核心：不断将 x 所在辅助树的右子树改为上一棵辅助树
void access(int x) {
    int z = 0;
    for (; x; z = x, x = tr[x].p) {
        splay(x);
        tr[x].s[1] = z; // 断开原右子树，连接上一棵
    }
}

// Makeroot 操作：将 x 变为所在树的根
// 先 access(x)，再 splay(x)，最后翻转整棵树
void makeroot(int x) {
    access(x);
    splay(x);
    pushrev(x);
}

// Findroot 操作：查询 x 所在树的根
// access(x) 后，最左边的节点就是根
int findroot(int x) {
    access(x);
    splay(x);
    while (tr[x].s[0]) {
        pushdown(x);
        x = tr[x].s[0];
    }
    splay(x);
    return x;
}

// Split 操作：将 x 到 y 的路径提取为一条链
// makeroot(x) 使 x 成为根，access(y) 后 y 到 x 的路径成为一条链
void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
}

// Link 操作：连接 x 和 y
// 先 makeroot(x)，再判断 x 和 y 不在同一棵树中，然后连接
void link(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) tr[x].p = y;
}

// Cut 操作：断开 x 和 y 的边
// 先 makeroot(x)，再判断 x 和 y 相连且 y 的父节点是 x，然后断开
void cut(int x, int y) {
    makeroot(x);
    if (findroot(y) == x && tr[y].p == x && !tr[y].s[0]) {
        tr[y].p = tr[x].s[1] = 0;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    while (m--) {
        char op[2];
        int x, y;
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'C') link(x, y);
        else if (op[0] == 'D') cut(x, y);
        else {
            split(x, y);
            if (findroot(x) == findroot(y)) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
