#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

int a[N];
int n, p;

struct Node {
    int l, r;
    int sum;
    int add, mul;
} tr[N * 4];

void eval(int u, int mul, int add) {
    tr[u].sum = (tr[u].sum * mul % p + (tr[u].r - tr[u].l + 1) * add % p) % p;
    tr[u].mul = (tr[u].mul * mul) % p;
    tr[u].add = (tr[u].add * mul % p + add) % p;
}

void pushup(Node &root, Node &left, Node &right) {
    root.sum = (left.sum + right.sum) % p;
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void pushdown(int u) {
    if (tr[u].add != 0 || tr[u].mul != 1) {
        eval(u << 1, tr[u].mul, tr[u].add);
        eval(u << 1 | 1, tr[u].mul, tr[u].add);
        tr[u].add = 0;
        tr[u].mul = 1;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0, 1};
    if (l == r) {
        tr[u].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

// type=0:乘法 1:加法
void modify(int u, int l, int r, int v, int type) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (type == 0) {
            eval(u, v, 0);
        } else {
            eval(u, 1, v);
        }
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, v, type);
    if (r > mid)
        modify(u << 1 | 1, l, r, v, type);
    pushup(u);
}

int quary(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid)
        res = (res + quary(u << 1, l, r)) % p;
    if (r > mid)
        res = (res + quary(u << 1 | 1, l, r)) % p;
    return res;
}

void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);

    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int t, g, c;
            cin >> t >> g >> c;
            modify(1, t, g, c, 0);
        } else if (op == 2) {
            int t, g, c;
            cin >> t >> g >> c;
            modify(1, t, g, c, 1);
        } else {
            int t, g;
            cin >> t >> g;
            cout << quary(1, t, g) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
