#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

struct Node {
    int l, r;
    int sum, add;
} tr[N * 4];

int a[N];

void pushup(Node &u, Node &l, Node &r) { u.sum = l.sum + r.sum; }

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void pushdown(int u) {
    Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add;
        left.sum += (left.r - left.l + 1) * root.add;
        right.add += root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    // cout << u << ' ' << l << ' ' << r << endl;
    // return;
    if (tr[u].l == tr[u].r) {
        tr[u].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int v) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += v * (tr[u].r - tr[u].l + 1);
        tr[u].add += v;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, v);
        if (r > mid)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

int quary(int u, int l, int r) {
    // cout << "---" << u << ' ' << l << ' ' << r << endl;
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    int ans = 0;
    if (l <= mid)
        ans += quary(u << 1, l, r);
    if (r > mid)
        ans += quary(u << 1 | 1, l, r);
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // cout << 1 << endl;
    // exit(0);
    build(1, 1, n);
    // cout << 1 << endl;
    // exit(0);

    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            modify(1, l, r, d);
        } else {
            int l, r;
            cin >> l >> r;
            cout << quary(1, l, r) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}