// 平衡树 (Splay)
// AcWing 104. 仓库选址 / 153. 普通平衡树
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 1e9;

int n, m, root, idx;
int tr[N][2], parent[N], cnt[N], size[N], key[N];

void pushup(int x) {
    size[x] = size[tr[x][0]] + size[tr[x][1]] + cnt[x];
}

bool get(int x) {
    return tr[parent[x]][1] == x;
}

void rotate(int x) {
    int y = parent[x], z = parent[y];
    int k = get(x);
    tr[y][k] = tr[x][k ^ 1];
    parent[tr[x][k ^ 1]] = y;
    tr[x][k ^ 1] = y;
    parent[y] = x;
    tr[z][get(y)] = x;
    parent[x] = z;
    pushup(y);
    pushup(x);
}

void splay(int x, int k) {
    while (parent[x] != k) {
        int y = parent[x], z = parent[y];
        if (z != k) {
            if (get(x) == get(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if (!k) root = x;
}

void insert(int v) {
    int x = root, p = 0;
    while (x && key[x] != v) {
        p = x;
        size[x]++;
        x = tr[x][v > key[x]];
    }
    if (x) cnt[x]++;
    else {
        x = ++idx;
        key[x] = v;
        cnt[x] = 1;
        size[x] = 1;
        parent[x] = p;
        tr[p][v > key[p]] = x;
    }
    splay(x, 0);
}

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

void remove(int v) {
    int r1 = get_rank(v);
    int r2 = get_rank(v + 1);
    splay(get_val(r1), 0);
    splay(get_val(r2), root);
    int del = tr[root][1][0];
    if (cnt[del] > 1) {
        cnt[del]--;
        splay(del, 0);
    } else {
        tr[root][1][0] = 0;
        splay(root, 0);
    }
}

int main() {
    insert(-INF);
    insert(INF);

    scanf("%d", &n);
    while (n--) {
        int op, x;
        scanf("%d%d", &op, &x);
        switch (op) {
            case 1: insert(x); break;
            case 2: remove(x); break;
            case 3: printf("%d\n", get_rank(x)); break;
            case 4: printf("%d\n", get_val(x + 1)); break;
            case 5: printf("%d\n", get_prev(x)); break;
            case 6: printf("%d\n", get_next(x)); break;
        }
    }

    return 0;
}
