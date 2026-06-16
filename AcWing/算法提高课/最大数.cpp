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
const int N = 2e5 + 10;

int n;
struct Node {
    int l, r;
    int mx;
} tr[N * 4];

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r};
    } else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void pushup(int u) { tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx); }

int quary(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].mx;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid)
        v = quary(u << 1, l, r);
    if (r > mid)
        v = max(v, quary(u << 1 | 1, l, r));
    return v;
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].mx = v;
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

void solve() {
    int m, p;
    cin >> m >> p;
    build(1, 1, m);
    int a = 0;
    while (m--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'Q') {
            a = quary(1, n - x + 1, n);
            cout << a << endl;
        } else {
            modify(1, n + 1, (x + a) % p);
            n++;
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
