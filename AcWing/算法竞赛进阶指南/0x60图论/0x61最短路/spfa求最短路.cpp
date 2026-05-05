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
constexpr int N = 1e5 + 10;

int n, m;
int d[N];
int v[N];
queue<int> q;

int head[N], ne[N], ver[N], edge[N], tot;

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    ne[tot] = head[x];
    head[x] = tot;
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }

    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    v[1] = 1;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
    if (d[n] == INF)
        cout << "impossible" << endl;
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