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
constexpr int N = 510;

int n, m;
int g[N][N];
int d[N];
int v[N];

void solve() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    FOR(i, 1, n) g[i][i] = 0;
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    FOR(i, 1, n) {
        int x = -1;
        FOR(i, 1, n) {
            if (x == -1 && !v[i] || !v[i] && d[i] < d[x])
                x = i;
        }
        v[x] = 1;
        FOR(i, 1, n) d[i] = min(d[i], d[x] + g[x][i]);
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