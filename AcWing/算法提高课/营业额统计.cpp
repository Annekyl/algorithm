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

constexpr int INF = 1e9;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

struct Node {
    int l, r;
    int key, val;
    int sz, cnt;
} tr[N];

int root, idx;

int get_node(int val) {
    tr[++idx].key = val;
    tr[idx].val = rand();
    tr[idx].sz = tr[idx].cnt = 1;
    return idx;
}

void pushup(int u) { tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + tr[u].cnt; }

// 右旋
void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}

// 左旋
void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l);
    pushup(p);
}

void build() {
    get_node(-INF), get_node(INF);
    root = 1;
    tr[1].r = 2;
    pushup(root);

    // 维护大根堆性质
    if (tr[1].val < tr[2].val)
        zag(root);
}

void insert(int &p, int x) {
    if (!p)
        p = get_node(x);
    else if (tr[p].key == x)
        tr[p].cnt++;
    else if (x < tr[p].key) {
        // 插入左子树
        insert(tr[p].l, x);
        if (tr[tr[p].l].val > tr[p].val)
            zig(p);
    } else {
        insert(tr[p].r, x);
        if (tr[tr[p].r].val > tr[p].val)
            zag(p);
    }
    pushup(p);
}

void remove(int &p, int key) {
    if (!p)
        return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1)
            tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            // 右旋
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            } else {
                // 左旋
                zag(p);
                remove(tr[p].l, key);
            }
        } else
            p = 0;
    } else if (key < tr[p].key)
        remove(tr[p].l, key);
    else
        remove(tr[p].r, key);
    pushup(p);
}

int get_rank_by_key(int p, int key) {
    if (!p)
        return 0;
    if (tr[p].key == key)
        return tr[tr[p].l].sz + 1;
    else if (key < tr[p].key)
        return get_rank_by_key(tr[p].l, key);
    else
        return tr[tr[p].l].sz + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}

int get_key_by_rank(int p, int rank) {
    if (!p) // 查询失败
        return -1;
    if (tr[tr[p].l].sz >= rank)
        return get_key_by_rank(tr[p].l, rank);
    else if (tr[tr[p].l].sz + tr[p].cnt >= rank)
        return tr[p].key;
    else
        return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].sz - tr[p].cnt);
}

// 找小于等于key的值
int get_pre(int p, int key) {
    if (!p) // 查询失败
        return -INF;
    if (tr[p].key <= key)
        return max(tr[p].key, get_pre(tr[p].r, key));
    return get_pre(tr[p].l, key);
}

// 找大于等于key的值
int get_next(int p, int key) {
    if (!p)
        return INF;
    if (tr[p].key >= key) {
        return min(tr[p].key, get_next(tr[p].l, key));
    } else {
        return get_next(tr[p].r, key);
    }
}

void solve() {
    int n;
    cin >> n;
    build();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i) {
            int pre = get_pre(root, x);
            int ne = get_next(root, x);
            ans += min(abs(x - pre), abs(x - ne));
            // cout << x << ' ' << pre << ' ' << ne << endl;
        } else
            ans += x;
        insert(root, x);
    }
    cout << ans << endl;
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
