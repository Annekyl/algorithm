#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;
int a[N];

struct Node {
    int l, r;
    int sum;
} tr[N * 4];

void pushup(int x) { tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum; }

void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r, a[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int quary(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid)
        sum += quary(u << 1, l, r);
    if (r > mid)
        sum += quary(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r)
        tr[u].sum += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0) {
            int res = quary(1, a, b);
            cout << res << endl;
        } else {
            modify(1, a, b);
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