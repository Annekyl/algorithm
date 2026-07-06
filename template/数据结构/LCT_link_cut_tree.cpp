// Link-Cut Tree (LCT)
// AcWing 396. 猴子王国
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
struct Node {
    int s[2], p, v;
    int rev;
} tr[N];

int stk[N];

bool isroot(int x) {
    int p = tr[x].p;
    return tr[p].s[0] != x && tr[p].s[1] != x;
}

void pushup(int x) {
}

void pushrev(int x) {
    swap(tr[x].s[0], tr[x].s[1]);
    tr[x].rev ^= 1;
}

void pushdown(int x) {
    if (tr[x].rev) {
        if (tr[x].s[0]) pushrev(tr[x].s[0]);
        if (tr[x].s[1]) pushrev(tr[x].s[1]);
        tr[x].rev = 0;
    }
}

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

void splay(int x) {
    int top = 0, y = x;
    stk[++top] = y;
    while (!isroot(y)) {
        y = tr[y].p;
        stk[++top] = y;
    }
    while (top) pushdown(stk[top--]);

    while (!isroot(x)) {
        y = tr[x].p;
        if (!isroot(y)) {
            if ((tr[y].s[1] == x) ^ (tr[tr[y].p].s[1] == y))
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
}

void access(int x) {
    int z = 0;
    for (; x; z = x, x = tr[x].p) {
        splay(x);
        tr[x].s[1] = z;
    }
}

void makeroot(int x) {
    access(x);
    splay(x);
    pushrev(x);
}

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

void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
}

void link(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) tr[x].p = y;
}

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
