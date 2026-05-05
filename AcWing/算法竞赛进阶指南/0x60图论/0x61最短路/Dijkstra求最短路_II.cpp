#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 2e5 + 10;

int n, m;
int d[N];
int v[N];

int ver[N], edge[N], head[N], ne[N], tot;

void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z;
    ne[tot] = head[x], head[x] = tot;
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    priority_queue<pii> q;
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    q.push({0, 1});
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = 1;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i], z = edge[i];
            if (!v[y]) {
                if (d[y] > d[x] + z) {
                    d[y] = d[x] + z;
                    q.push({-d[y], y});
                }
            }
        }
    }
    if (d[n] == INF)
        cout << -1;
    else
        cout << d[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}