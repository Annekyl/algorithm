#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 510;

struct rec {
    int x, y, st;
};

int n, m;
char g[N][N];   // 地图
rec st, ed;     // 起点和终点
int d[N][N][3]; // 距离

int dx[4] = {0, 0, -1, 1}; // 左右上下
int dy[4] = {-1, 1, 0, 0};

void get_st() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'O') {
                ed.x = i;
                ed.y = j;
                ed.st = 0;
                g[i][j] = '.';
                continue;
            }
            if (g[i][j] == 'X') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (g[nx][ny] == 'X') {
                        st.x = min(nx, i);
                        st.y = min(ny, j);
                        st.st = k < 2 ? 1 : 2;
                        g[nx][ny] = g[i][j] = '.';
                        break;
                    }
                }
                if (g[i][j] == 'X') {
                    st.x = i;
                    st.y = j;
                    st.st = 0;
                    g[i][j] = '.';
                }
            }
        }
    }
}

int ne_dx[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
int ne_dy[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
int ne_dlie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};

bool valid(int x, int y, int lie) {
    if (x < 1 || x > n || y < 1 || y > m)
        return 0;
    if (g[x][y] == '#')
        return 0;
    if (g[x][y] == 'E' && lie == 0)
        return 0;
    if (lie == 1 && g[x][y + 1] == '#')
        return 0;
    if (lie == 2 && g[x + 1][y] == '#')
        return 0;
    return 1;
}

int bfs() {
    memset(d, 0xcf, sizeof d);
    queue<rec> q;
    d[st.x][st.y][st.st] = 0;
    q.push(st);
    while (q.size()) {
        auto now = q.front();
        q.pop();
        int x = now.x, y = now.y, lie = now.st;
        // cout << x << " " << y << " " << lie << endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + ne_dx[lie][i];
            int ny = y + ne_dy[lie][i];
            int nlie = ne_dlie[lie][i];
            if (!valid(nx, ny, nlie))
                continue;
            if (d[nx][ny][nlie] == 0xcfcfcfcf) {
                d[nx][ny][nlie] = d[x][y][lie] + 1;
                rec ne_rec = {nx, ny, nlie};
                q.push(ne_rec);
                if (ed.x == nx && ny == ed.y && nlie == ed.st) {
                    return d[nx][ny][nlie];
                }
            }
        }
    }
    // cout << "Error" << endl;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m, n != 0 && m != 0) {
        // cout << n << m << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        get_st();
        int res = bfs();
        if (res == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}