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
constexpr int N = 110;

int n, m;
int g[N][N];
int d[N][N];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) { cin >> g[i][j]; }
    }

    memset(d, 0, sizeof d);
    queue<pii> q;
    q.push({1, 1});
    d[1][1] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n && y == m) {
            cout << d[x][y];
            break;
        }
        FOR(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && !d[nx][ny] && g[nx][ny] == 0) {
                q.push({nx, ny});
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
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