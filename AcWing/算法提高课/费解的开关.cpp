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
const int N = 1e5 + 10;

int g[10][10];
int backup[10][10];
int ans = 0;
int cnt = 0;

int dx[5] = {-1, 0, 0, 0, 1};
int dy[5] = {0, -1, 0, 1, 0};

bool valid(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5; }

void dfs(int x, int y) {
    // cout << x << ' ' << y << endl;
    int ny = y + 1 < 5 ? y + 1 : 0;
    int nx = ny == 0 ? x + 1 : x;

    if (!g[x - 1][y]) {
        for (int i = 0; i < 5; i++) {
            int nex = x + dx[i];
            int ney = y + dy[i];
            if (valid(nex, ney)) {
                g[nex][ney] ^= 1;
            }
        }
        cnt++;
    }

    if (nx >= 5) {
        for (int i = 0; i < 5; i++) {
            if (!g[4][i])
                return;
        }
        ans = min(ans, cnt);

        // for (int i = 0; i < 5; i++) {
        //     for (int j = 0; j < 5; j++) {
        //         cout << g[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl << endl;
        return;
    }

    dfs(nx, ny);
}

void solve() {
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        s = s;
        for (int j = 0; j < 5; j++) {
            g[i][j] = s[j] - '0';
            backup[i][j] = g[i][j];
        }
    }

    ans = INF;
    for (int i = 0; i < (1 << 5); i++) {
        memcpy(g, backup, sizeof backup);

        cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < 5; k++) {
                    int x = dx[k], y = j + dy[k];
                    if (valid(x, y))
                        g[x][y] ^= 1;
                }
                cnt++;
            }
        }
        dfs(1, 0);
    }
    cout << (ans > 6 ? -1 : ans) << endl;
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
