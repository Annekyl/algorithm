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
constexpr int N = 310;

int n, m;
int g[N][N];
int f[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int dfs(int x, int y) {
    if (f[x][y] != 0)
        return f[x][y];
    f[x][y] = 1;
    FOR(i, 0, 3) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) && g[nx][ny] < g[x][y]) {
            f[x][y] = max(f[x][y], dfs(nx, ny) + 1);
        }
    }
    return f[x][y];
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) { cin >> g[i][j]; }
    }

    int ans = -1;
    FOR(i, 1, n) {
        FOR(j, 1, m) { ans = max(ans, dfs(i, j)); }
    }

    // FOR(i, 1, n) {
    //     FOR(j, 1, m) { cout << f[i][j] << " "; }
    //     cout << endl;
    // }
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