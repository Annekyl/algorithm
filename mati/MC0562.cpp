#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 2e5 + 10;

int n, m;
int fa[N];
int sz[N];
int edge[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
        edge[i] = 0;
    }
}

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) {
        edge[fx]++;
        return;
    }
    fa[fx] = fy;
    sz[fy] += sz[fx];
    edge[fy] += edge[fx] + 1;
}

void solve() {
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) != i)
            continue;
        if (sz[i] % 2 == edge[i] % 2)
            ans += sz[i];
        else
            ans += sz[i] - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}