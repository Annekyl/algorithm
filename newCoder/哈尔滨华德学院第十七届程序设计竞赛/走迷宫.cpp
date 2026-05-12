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
const int N = 15;

struct Point {
    int x, y, z, t;
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y && z == other.z && t == other.t;
    }
};
char g[N][N][N][N];
bool v[N][N][N][N];

void solve() {
    memset(v, 0, sizeof v);
    int n;
    cin >> n;
    Point st, ed;
    for (int t = 1; t <= n; t++) {
        for (int z = 1; z <= n; z++) {
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    cin >> g[x][y][z][t];
                    if (g[x][y][z][t] == 'S') {
                        // debug(x);
                        // debug(y);
                        // debug(z);
                        // debug(t);
                        st = {x, y, z, t};
                    } else if (g[x][y][z][t] == 'E') {
                        ed = {x, y, z, t};
                    }
                }
            }
        }
    }
    // cout << st.x << " " << st.y << " " << st.z << " " << st.t << endl;

    int dx[8] = {0, 0, 0, 1, 0, 0, 0, -1};
    int dy[8] = {0, 0, 1, 0, 0, 0, -1, 0};
    int dz[8] = {0, 1, 0, 0, 0, -1, 0, 0};
    int dt[8] = {1, 0, 0, 0, -1, 0, 0, 0};
    auto valid = [&](int x, int y, int z, int t) {
        if (x < 1 || y < 1 || z < 1 || t < 1 || x > n || y > n || z > n ||
            t > n)
            return false;
        return g[x][y][z][t] != '#';
    };

    int ans = -1;
    queue<pair<Point, int>> q;
    q.push({st, 0});
    while (q.size()) {
        auto [point, dist] = q.front();
        // cout << point.x << ' ' << point.y << ' ' << point.z << ' ' << point.t
        //      << endl;
        q.pop();
        auto [x, y, z, t] = point;
        if (v[x][y][z][t])
            continue;
        v[x][y][z][t] = true;
        if (point == ed) {
            ans = dist;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int nx = point.x + dx[i];
            int ny = point.y + dy[i];
            int nz = point.z + dz[i];
            int nt = point.t + dt[i];
            if (valid(nx, ny, nz, nt) && !v[nx][ny][nz][nt]) {
                q.push({{nx, ny, nz, nt}, dist + 1});
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
