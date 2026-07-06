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
int tr1[N], tr2[N];

int lowbit(int x) { return x & -x; }

void add1(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr1[i] += v;
}

void add2(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr2[i] += v;
}

int quary1(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr1[i];
    }
    return res;
}

int quary2(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr2[i];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    int a[n + 1] = {0}, d[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        add1(i, d[i]);
        add2(i, i * d[i]);
    }

    while (m--) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            int s1 = quary1(l - 1) * l - quary2(l - 1);
            int s2 = quary1(r) * (r + 1) - quary2(r);
            cout << s2 - s1 << endl;
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            add1(l, d);
            add1(r + 1, -d);
            add2(l, d * l);
            add2(r + 1, (r + 1) * (-d));
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
