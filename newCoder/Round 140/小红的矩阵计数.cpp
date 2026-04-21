#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'
#define forr(i, l, r) for (int i = (l); i <= (r); ++i)
#define ref(i, l, r) for (int i = (l); i >= (r); --i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010;

int g[N][N];

int judge(int x, int y) {
    int res = 0;
    if (g[x][y] != g[x][y + 1] && g[x][y] != g[x + 1][y + 1] &&
        g[x][y + 1] != g[x + 1][y + 1])
        res++;

    if (g[x][y] != g[x][y + 1] && g[x][y] != g[x + 1][y] &&
        g[x][y + 1] != g[x + 1][y])
        res++;

    if (g[x][y] != g[x + 1][y] && g[x][y] != g[x + 1][y + 1] &&
        g[x + 1][y + 1] != g[x + 1][y])
        res++;

    if (g[x][y + 1] != g[x + 1][y] && g[x][y + 1] != g[x + 1][y + 1] &&
        g[x + 1][y + 1] != g[x + 1][y])
        res++;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            ans += judge(i, j);
        }
    }
    cout << ans << endl;
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
