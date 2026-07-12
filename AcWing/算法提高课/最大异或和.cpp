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
const int N = 6e5 + 10;

int a[N], s[N];

int tr[N * 25][2], mx_id[N * 25], idx;
int root[N];

void insert(int i, int pos, int pre, int cur) {
    if (pos < 0) {
        mx_id[cur] = i;
        return;
    }
    int v = s[i] >> pos & 1;
    if (pre)
        tr[cur][v ^ 1] = tr[pre][v ^ 1];
    tr[cur][v] = ++idx;
    insert(i, pos - 1, tr[pre][v], tr[cur][v]);
    mx_id[cur] = max(mx_id[tr[cur][0]], mx_id[tr[cur][1]]);
}

int quary(int root, int left, int c) {
    int p = root;
    for (int i = 23; i >= 0; i--) {
        int v = c >> i & 1;
        if (mx_id[tr[p][v ^ 1]] >= left) {
            p = tr[p][v ^ 1];
        } else {
            p = tr[p][v];
        }
    }
    return s[mx_id[p]] ^ c;
}

void solve() {
    int n, m;
    cin >> n >> m;

    mx_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        root[i] = ++idx;
        insert(i, 23, root[i - 1], root[i]);
    }

    while (m--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int x;
            cin >> x;
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n, 23, root[n - 1], root[n]);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            int ans = quary(root[r - 1], l - 1, s[n] ^ x);
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
