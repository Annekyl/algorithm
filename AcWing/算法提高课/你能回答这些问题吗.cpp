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
const int N = 5e5 + 10;

struct Node {
    int l, r;
    int sum, lmx, rmx, tmx;
} tr[N * 4];

int a[N];

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
    u.lmx = max(l.lmx, l.sum + r.lmx);
    u.rmx = max(r.rmx, r.sum + l.rmx);
    u.tmx = max({l.tmx, r.tmx, l.rmx + r.lmx});
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[l], a[l], a[l], a[l]};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].sum = tr[u].lmx = tr[u].rmx = tr[u].tmx = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)
        modify(u << 1, x, v);
    else
        modify(u << 1 | 1, x, v);
    pushup(u);
}

Node quary(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];

    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid)
        return quary(u << 1, l, r);
    else if (l > mid)
        return quary(u << 1 | 1, l, r);
    else {
        // 横跨两段
        Node left = quary(u << 1, l, r);
        Node right = quary(u << 1 | 1, l, r);
        Node res;
        pushup(res, left, right);
        return res;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);
    // cout << 1 << endl;
    // exit(0);
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            if (x > y)
                swap(x, y);
            auto res = quary(1, x, y);
            cout << res.tmx << endl;
        } else {
            modify(1, x, y);
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
