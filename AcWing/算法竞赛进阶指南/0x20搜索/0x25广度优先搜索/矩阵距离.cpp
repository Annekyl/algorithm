#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int n, m;
int g[N][N];
int d[N][N];
queue<pii> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(d, 0xcf, sizeof d);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            g[i][j] = s[j - 1] - '0';
            if (g[i][j] == 1) {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << g[i][j] << " ";
    //         // cout<<d[i][j]<<" ";
    //     }
    //     cout << endl;
    // }

    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                if (d[nx][ny] == 0xcfcfcfcf) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}