#include <iostream>
#include <random>

using namespace std;

struct Node {
    int l, r, size, priority;
    int time;
    long long val;
};

Node tree[1000005];
int cnt = 0;
mt19937 rng(1337);

int new_node(int t, long long v) {
    int u = ++cnt;
    tree[u].time = t;
    tree[u].val = v;
    tree[u].size = 1;
    tree[u].priority = rng();
    tree[u].l = tree[u].r = 0;
    return u;
}

void push_up(int u) {
    tree[u].size = tree[tree[u].l].size + tree[tree[u].r].size + 1;
}

void split(int u, int k, int &l, int &r) {
    if (!u) { l = r = 0; return; }
    if (tree[tree[u].l].size + 1 <= k) {
        l = u;
        split(tree[u].r, k - tree[tree[u].l].size - 1, tree[u].r, r);
    } else {
        r = u;
        split(tree[u].l, k, l, tree[u].l);
    }
    push_up(u);
}

int merge(int l, int r) {
    if (!l || !r) return l + r;
    if (tree[l].priority > tree[r].priority) {
        tree[l].r = merge(tree[l].r, r);
        push_up(l);
        return l;
    } else {
        tree[r].l = merge(l, tree[r].l);
        push_up(r);
        return r;
    }
}

pair<int, long long> query(int &root, int k) {
    int l, mid, r;
    split(root, k - 1, l, r);
    split(r, 1, mid, r);
    pair<int, long long> res = {tree[mid].time, tree[mid].val};
    root = merge(l, merge(mid, r));
    return res;
}

void insert(int &root, int x, int t, long long v) {
    int l, r;
    split(root, x, l, r);
    root = merge(merge(l, new_node(t, v)), r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    long long c;
    cin >> q >> c;

    int row_root = 0, col_root = 0;
    insert(row_root, 0, 0, c);
    insert(col_root, 0, 0, c);

    for (int t = 1; t <= q; ++t) {
        int opt, x;
        long long y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            insert(row_root, x, t, y);
        } else if (opt == 2) {
            insert(col_root, x, t, y);
        } else {
            auto r_info = query(row_root, x);
            auto c_info = query(col_root, (int)y);
            if (r_info.first > c_info.first) cout << r_info.second << "\n";
            else cout << c_info.second << "\n";
        }
    }

    return 0;
}