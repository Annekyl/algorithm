#include "bits/stdc++.h"

// #define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1010;

int n, m;
char g[N][N];
int edx, edy;
int d[N][N][3];

// 0竖立 1横卧(记录左边坐标) 2竖卧(记录上面坐标)
// 上下左右移动
int dx[3][4] = {{-2, 1, 0, 0}, {-1, 1, 0, 0}, {-1, 2, 0, 0}};
int dy[3][4] = {{0, 0, 1, -2}, {0, 0, 2, -1}, {0, 0, 1, -1}};
int dz[3][4] = {{2, 2, 1, 1}, {1, 1, 0, 0}, {0, 0, 2, 2}};

bool valid(int x, int y, int z) {
    // 竖立状态
    if (z == 0) {
        if (x < 1 || x > n || y < 1 || y > m)
            return false;
        if (g[x][y] != '1' && g[x][y] != '3')
            return false;
    } else if (z == 1) { // 横卧状态
        if (x < 1 || x > n || y < 1 || y + 1 > m)
            return false;
        if (g[x][y] == '0' || g[x][y + 1] == '0')
            return false;
    } else if (z == 2) { // 竖卧
        if (x < 1 || x + 1 > n || y < 1 || y > m || g[x][y] == '0' ||
            g[x + 1][y] == '0') {
            // cout << "2false" << endl;
            return false;
        }
    }
    return true;
}

void bfs() {
    memset(d, 0x3f, sizeof d);

    // 队列初始化
    queue<tuple<int, int, int>> q;
    q.push({edx, edy, 0});
    d[edx][edy][0] = 0;

    while (q.size()) {
        auto [x, y, z] = q.front();
        q.pop();

        // cout << x << " " << y << " " << z << " " << step << endl;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[z][i];
            int ny = y + dy[z][i];
            int nz = dz[z][i];
            // cout << nx << " " << ny << " " << nz << endl;

            if (!valid(nx, ny, nz))
                continue;
            // cout << "push:";
            // cout << nx << " " << ny << " " << nz << endl;
            if (d[nx][ny][nz] == INF) {
                d[nx][ny][nz] = d[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '3') {
                edx = i, edy = j;
            }
        }
    }

    bfs();

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << (d[x][y][z] == INF ? -1 : d[x][y][z]) << endl;
    }

    return 0;
}