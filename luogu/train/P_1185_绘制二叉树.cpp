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

int n, m;
bool is_del[11][1100];
int d[15];
char g[2000][2000];

void draw(int r, int c, int layer, int idx) {
    if (layer > m || is_del[layer][idx])
        return;

    g[r][c] = 'o';
    if (layer == m)
        return;

    int dist = d[layer];
    int left = idx * 2 - 1;
    int right = idx * 2;

    if (!is_del[layer + 1][left]) {
        for (int k = 1; k < dist; k++) {
            g[r + k][c - k] = '/';
        }
        draw(r + dist, c - dist, layer + 1, left);
    }
    if (!is_del[layer + 1][right]) {
        for (int k = 1; k < dist; k++) {
            g[r + k][c + k] = '\\';
        }
        draw(r + dist, c + dist, layer + 1, right);
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        is_del[x][y] = true;
    }
    d[m - 1] = 2;
    if (m > 2) {
        d[m - 2] = 3;
        for (int i = m - 3; i >= 1; i--) {
            d[i] = d[i + 1] * 2;
        }
    }
    int h = 1;
    for (int i = 1; i < m; i++) {
        h += d[i];
    }
    int w = h * 2 - 1;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            g[i][j] = ' ';

    draw(0, h - 1, 1, 1);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << g[i][j];
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
