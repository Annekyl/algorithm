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

const int N = 1e5 + 10;

int n, m;
int fa[N];
int sz[N];
int line[N];

void init() {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        line[i] = 0;
        sz[i]++;
    }
}

int get(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int a, int b) {
    if (a == b)
        return;
    a = get(a), b = get(b);
    if (a < b)
        swap(a, b);

    sz[b] += sz[a];
    fa[a] = b;
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        line[a]++, line[b]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i)
            ans++;
    }
    cout << ans << " ";
    int cnt = (2 * ans + n - 1) / n;
    cout << cnt << endl;
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
