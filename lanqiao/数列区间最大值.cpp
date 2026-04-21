#include "bits/stdc++.h"
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, m, a[N];

struct Node {
    int l, r;
    int mx;
} tr[N * 4];

void pushup(int x) { tr[x].mx = max(tr[x << 1].mx, tr[x << 1 | 1].mx); }

void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r, a[l]};
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
        return tr[u].mx;
    int mid = tr[u].l + tr[u].r >> 1;
    int mx = INT_MIN;
    if (l <= mid)
        mx = max(mx, quary(u << 1, l, r));
    if (r > mid)
        mx = max(mx, quary(u << 1 | 1, l, r));
    return mx;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << quary(1, x, y) << endl;
    }
}

int main() {
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