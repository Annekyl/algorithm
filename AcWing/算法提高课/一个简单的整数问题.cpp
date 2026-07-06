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
int tr[N];

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += v;
    }
}

int quary(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    int a[n + 1] = {0}, d[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        add(i, d[i]);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << tr[i] << ' ';
    // cout << endl;

    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d);
            add(r + 1, -d);
        } else {
            int x;
            cin >> x;
            int ans = quary(x);
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
