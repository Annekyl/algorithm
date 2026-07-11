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

int a[N], d[N];

struct Node {
    int l, r;
    int sum, g;
} tr[N * 4];

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
    u.g = abs(__gcd(l.g, r.g));
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, d[l], abs(d[l])};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

// d[x] += v
void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r && tr[u].l == x) {
        tr[u].sum += v;
        tr[u].g = abs(tr[u].sum);
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
    if (l > r)
        return {0, 0, 0, 0};
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u];
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l > mid) {
        return quary(u << 1 | 1, l, r);
    } else if (r <= mid) {
        return quary(u << 1, l, r);
    } else {
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
        d[i] = a[i] - a[i - 1];
    }

    build(1, 1, n);

    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        } else {
            int l, r;
            cin >> l >> r;
            Node left = quary(1, 1, l);
            Node right = quary(1, l + 1, r);
            int ans = abs(__gcd(left.sum, right.g));
            cout << ans << endl;
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
