#include "bits/stdc++.h"
// #include <bits/extc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// typedef tree<int, int, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_map;

// typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 3e6 + 10;

struct Node {
    int l, r;
    int sz;
    int res;
} tr[N];

int tot = 0;

int create() {
    int u = ++tot;
    tr[u].l = tr[u].r = tr[u].sz = tr[u].res = 0;
    return u;
}

void update(int u, int d) {
    tr[u].sz = tr[u].res = 0;
    if (tr[u].l) {
        tr[u].sz ^= tr[tr[u].l].sz;
        tr[u].res ^= tr[tr[u].l].res;
    }

    if (tr[u].r) {
        tr[u].sz ^= tr[tr[u].r].sz;
        tr[u].res ^= tr[tr[u].r].res;
        if (tr[tr[u].r].sz) {
            tr[u].res ^= (1 << d);
        }
    }
}

void flip(int &u, int v, int d) {
    if (!u)
        u = create();
    if (d == 20) {
        tr[u].sz ^= 1;
        return;
    }
    if ((v >> d) & 1) {
        flip(tr[u].r, v, d + 1);
    } else {
        flip(tr[u].l, v, d + 1);
    }
    update(u, d);
}

void sub(int u, int d) {
    if (!u)
        return;
    if (d == 20)
        return;
    swap(tr[u].l, tr[u].r);
    sub(tr[u].r, d + 1);
    update(u, d);
}

int pop_zero(int u, int d) {
    if (!u)
        return 0;
    if (d == 20) {
        int c = tr[u].sz;
        tr[u].sz = 0;
        tr[u].res = 0;
        return c;
    }
    int c = pop_zero(tr[u].l, d + 1);
    update(u, d);
    return c;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int root = 0;
    int offset = 0;
    vi a(n + 1, 0);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;

            int old_v = max(0LL, a[x] - offset);
            if (old_v > 0) {
                flip(root, old_v, 0);
            }
            int new_v = old_v + 1;
            flip(root, new_v, 0);
            a[x] = offset + new_v;

        } else {
            if (root) {
                sub(root, 0);
                pop_zero(root, 0);
            }
            offset++;
        }

        int ans = 0;
        if (root) {
            ans = tr[root].res;
        }
        cout << ans << endl;
    }
}

void solve2() {
    int n, q;
    cin >> n >> q;

    vi a(n + 1, 0);
    vi pos(n + 1);
    int tot = 0, ans = 0;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            ans ^= a[x];
            a[x]++;
            if (a[x] == 1)
                pos[++tot] = x;
            ans ^= a[x];
        } else {
            int cnt = 0;
            for (int i = 1; i <= tot; i++) {
                int idx = pos[i];
                ans ^= a[idx];
                a[idx]--;
                ans ^= a[idx];
                if (a[idx]) {
                    pos[++cnt] = idx;
                }
            }
            tot = cnt;
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();
        solve2();
    }

    return 0;
}
