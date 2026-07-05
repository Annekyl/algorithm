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
const int N = 1e3 + 10;

int n, m, a, b;
char g[N][N];
pii st, ed;
bool v[N][N];
int s[N][N];

bool check(int x, int y) {
    // cout << x << ' ' << y << endl;
    if (x + a - 1 > n || y + b - 1 > m || x <= 0 || y <= 0)
        return false;
    // for (int i = x; i < x + a; i++) {
    //     for (int j = y; j < y + b; j++) {
    //         if (g[i][j] == '#')
    //             return false;
    //     }
    // }
    // return true;
    int cnt = s[x + a - 1][y + b - 1] - s[x - 1][y + b - 1] -
              s[x + a - 1][y - 1] + s[x - 1][y - 1];
    // cout << cnt << endl;
    return cnt == 0;
}

void solve() {
    // memset(v, 0, sizeof v);
    // memset(s, 0, sizeof s);

    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                st = {i, j};
            } else if (g[i][j] == 'E') {
                ed = {i, j};
            }
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (g[i][j] == '#')
                s[i][j]++;
            // cout << s[i][j] << ' ';
        }
        // cout << endl;
    }

    // cout << (check(3, 2) ? "1" : "0") << endl;
    queue<pii> q;
    q.push(st);
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool suc = false;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        // if (v[x][y])
        // continue;
        // cout << x << ' ' << y << endl;
        // v[x][y] = true;
        if (x == ed.first && y == ed.second) {
            suc = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // cout << "---" << nx << " " << ny << endl;
            if (check(nx, ny)) {
                if (!v[nx][ny]) {
                    q.push({nx, ny});
                    v[nx][ny] = true;
                }
            }
        }
    }
    if (suc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = false;
            g[i][j] = 0;
        }
    }
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
