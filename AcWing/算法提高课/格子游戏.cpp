#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 300 * 300 + 10;

int n, m;

int fa[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    if (x == y)
        return;
    x = get(x), y = get(y);
    if (x < y)
        swap(x, y);
    fa[x] = y;
}

void solve() {
    cin >> n >> m;
    init();
    bool suc = false;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--, y--;
        int a, b;
        if (c == 'D') {
            // 向下连
            a = x * n + y, b = (x + 1) * n + y;
        } else {
            // 向右连
            a = x * n + y, b = x * n + y + 1;
        }
        // debug(a);
        // debug(b);
        // debug(get(a));
        // debug(get(b));
        if (get(a) == get(b)) {
            cout << i << endl;
            return;
        }
        merge(a, b);
        // cout << get(a) << endl;
    }

    cout << "draw" << endl;
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
