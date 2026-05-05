#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m, k;
int x, y, d;
char g[N][N];
bool v[N][N];

bool valid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void solve() {
    memset(v, 0, sizeof v);
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 1;
    v[x][y] = 1;
    for (int i = 1; i <= k; i++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (valid(nx, ny) && g[nx][ny] == '.') {
            x = nx, y = ny;
            if (!v[x][y]) {
                v[x][y] = 1;
                ans++;
            }
        } else {
            d = (d + 1) % 4;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}