#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1010;

int n, m;
struct State {
    int x, y, s;
};
char g[N][N];
int dist[N][N][3];

bool check(int x, int y, char s[]) // 判断(x, y)格子的状态是否在s中
{
    for (int i = 0; s[i]; i++)
        if (g[x][y] == s[i])
            return true;
    return false;
}

void bfs() {
    memset(dist, -1, sizeof dist);
    queue<State> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '3') {
                q.push({i, j, 0});
                dist[i][j][0] = 0;
            }

    State next[3][4] = {
        {{-2, 0, 2},
         {0, 1, 1},
         {1, 0, 2},
         {0, -2, 1}}, // 竖立状态下，朝上右下左滚动后的状态
        {{-1, 0, 1},
         {0, 2, 0},
         {1, 0, 1},
         {0, -1, 0}}, // 横卧状态下，朝上右下左滚动后的状态
        {{-1, 0, 0},
         {0, 1, 2},
         {2, 0, 0},
         {0, -1, 2}}, // 竖卧状态下，朝上右下左滚动后的状态
    };

    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            auto &d = next[t.s][i];
            State r = {t.x + d.x, t.y + d.y, d.s};
            if (r.s == 0 && !check(r.x, r.y, "1"))
                continue;
            if (r.s == 1 &&
                (!check(r.x, r.y, "123") || !check(r.x, r.y + 1, "123")))
                continue;
            if (r.s == 2 &&
                (!check(r.x, r.y, "123") || !check(r.x + 1, r.y, "123")))
                continue;
            if (dist[r.x][r.y][r.s] == -1) {
                dist[r.x][r.y][r.s] = dist[t.x][t.y][t.s] + 1;
                q.push(r);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i] + 1;
    bfs();

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y, s;
        cin >> x >> y >> s;
        cout << dist[x][y][s] << endl;
    }

    return 0;
}
