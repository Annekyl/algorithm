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
    u.g = __gcd(l.g, r.g);
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, d[l], abs(d[l])};
		return;
    }
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
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
        } else {
            int l, r;
            cin >> l >> r;
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
