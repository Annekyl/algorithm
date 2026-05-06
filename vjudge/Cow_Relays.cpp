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
const int N = 210;

struct matrix {
    int m[N][N];
};

int Hash[1010], cnt;

matrix operator*(const matrix &a, const matrix &b) {
    matrix c;
    memset(c.m, 0x3f, sizeof c.m);

    for (int i = 1; i <= cnt; i++) {
        for (int k = 1; k <= cnt; k++) {
            for (int j = 0; j <= cnt; j++) {
                c.m[i][j] = min(c.m[i][j], a.m[i][k] + b.m[k][j]);
            }
        }
    }

    return c;
}

matrix pow_matrix(matrix a, int p) {
    matrix res = a;
    p--;
    while (p) {
        if (p & 1)
            res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

void solve() {
    int n, t, s, e;
    cin >> n >> t >> s >> e;
    matrix g;
    memset(g.m, 0x3f, sizeof g.m);
    for (int i = 0; i < t; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (!Hash[x])
            Hash[x] = ++cnt;
        if (!Hash[y])
            Hash[y] = ++cnt;
        x = Hash[x];
        y = Hash[y];
        g.m[x][y] = g.m[y][x] = z;
    }

    matrix ans = pow_matrix(g, n);
    cout << ans.m[Hash[s]][Hash[e]] << endl;
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
