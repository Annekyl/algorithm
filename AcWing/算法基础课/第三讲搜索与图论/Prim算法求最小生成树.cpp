#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
int ans = 0;

void solve() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = min(g[x][y], z);
    }

    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    FOR(i, 1, n) {
        // 找到离当前树距离最近的点
        int x = -1;
        FOR(j, 1, n) {
            if (!v[j] && (x == -1 || d[x] > d[j])) {
                x = j;
            }
        }

        if (d[x] == INF) {
            cout << "impossible";
            return;
        }
        ans += d[x];
        v[x] = 1;
        FOR(y, 1, n) { d[y] = min(d[y], g[x][y]); }
    }
    cout << ans;
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