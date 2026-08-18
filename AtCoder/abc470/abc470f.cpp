#include "bits/stdc++.h"
// #include <bits/extc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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
const int N = 2e5 + 10;

int fa[N];

void init(int n) {
    for (int i = 0; i <= n; i++)
        fa[i] = i;
}

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}

int qmi(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vi a(m), b(m);
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        merge(a[i], b[i]);
    }

    // 预处理阶乘和逆元
    vi fact(n + 1, 0), ifac(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    ifac[n] = qmi(fact[n], mod - 2, mod);
    for (int i = n; i >= 1; i--) {
        ifac[i - 1] = ifac[i] * i % mod;
    }
    int ans = 1;
    vii st(n + 1); // 划分连通块
    for (int i = 1; i <= n; i++) {
        st[find(i)].push_back(i);
    }

    bool have_dup = false;
    for (int i = 1; i <= n; i++) {
        if (st[i].empty())
            continue;

        int sz = st[i].size();
        int add = fact[sz];
        vi cnt(26, 0);
        for (int x : st[i]) {
            cnt[s[x] - 'a']++;
            if (cnt[s[x] - 'a'] >= 2)
                have_dup = true;
        }
        for (int i = 0; i < 26; i++)
            add = add * ifac[cnt[i]] % mod;
        ans = (ans * add) % mod;
    }
    if (!have_dup)
        ans = ans * ifac[2] % mod;
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
