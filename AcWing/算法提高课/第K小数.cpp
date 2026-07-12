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

int n, m;
int a[N];
vi as;
int root[N], idx;

struct Node {
    int l, r;
    int cnt;
} tr[N * 4 + N * 17];

int get_pos(int x) {
    return lower_bound(as.begin(), as.end(), x) - as.begin() + 1;
}

int build(int l, int r) {
    int q = ++idx;
    tr[q].cnt = 0;
    if (l == r)
        return q;
    int mid = l + r >> 1;
    tr[q].l = build(l, mid);
    tr[q].r = build(mid + 1, r);
    return q;
}

int insert(int pre, int l, int r, int x) {
    int q = ++idx;
    tr[q] = tr[pre];
    tr[q].cnt++;
    if (l == r)
        return q;
    int mid = l + r >> 1;
    if (x <= mid) {
        tr[q].l = insert(tr[pre].l, l, mid, x);
    } else {
        tr[q].r = insert(tr[pre].r, mid + 1, r, x);
    }
    return q;
}

int quary(int p, int q, int l, int r, int k) {
    if (l == r)
        return l;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt)
        return quary(tr[p].l, tr[q].l, l, mid, k);
    else
        return quary(tr[p].r, tr[q].r, mid + 1, r, k - cnt);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        as.push_back(a[i]);
    }
    // 离散化a
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    int len = as.size();

    root[0] = build(1, len);
    for (int i = 1; i <= n; i++) {
        root[i] = insert(root[i - 1], 1, len, get_pos(a[i]));
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int pos = quary(root[l - 1], root[r], 1, len, k);
        cout << as[pos - 1] << endl;
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
