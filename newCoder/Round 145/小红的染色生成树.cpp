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
const int M = 2e5 + 10;

int n, m;
int fa[N];
vector<pii> tre;

struct Edge {
    int x, y, z;
    bool operator<(const Edge &other) const { return z < other.z; }
} edge[M];
int len;

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void init() {
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    tre.clear();
}

void kruskal(int need, int limit) {
    // debug(need);
    // debug(limit);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        auto [x, y, z] = edge[i];
        if (z != need)
            continue;
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            tre.push_back({x, y});
            fa[fx] = fy;
            cnt++;
            if (cnt == limit)
                return;
        }
    }
}

void solve() {
    cin >> n >> m;
    len = n - 1;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }
    sort(edge, edge + m);

    int st[3][2] = {{0, 1}, {0, 2}, {1, 2}};
    for (int i = 0; i < 3; i++) {
        init();
        kruskal(st[i][0], len - 1);
        kruskal(st[i][1], len - 1);
        if (tre.size() == len)
            break;

        init();
        kruskal(st[i][1], len - 1);
        kruskal(st[i][0], len - 1);
        if (tre.size() == len)
            break;
        // init();
        // kruskal(st[i][0], 1);
        // kruskal(st[i][1], len - 1);
        // if (tre.size() == len)
        //     break;
    }

    if (tre.size() != len) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < len; i++) {
        auto [x, y] = tre[i];
        cout << x << ' ' << y << endl;
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
