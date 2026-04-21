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

const int N = 2e5 + 10;
const int mod = 998244353;

int n, k;

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
    x = get(x), y = get(y);
    fa[x] = y;
}

void solve() {
    cin >> n >> k;
    init();
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        merge(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i)
            cnt++;
    }
    // debug(cnt);
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans = ans * 26 % mod;
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
