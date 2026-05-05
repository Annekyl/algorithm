#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1010;

int n, m, q;
int g[N][N];
int d[N][N];

void solve() {
    cin >> n >> m >> q;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> g[i][j];
            d[i][j] = g[i][j] - g[i - 1][j] - g[i][j - 1] + g[i - 1][j - 1];
        }
    }

    while (q--) {
        int a, b, x, y, c;
        cin >> a >> b >> x >> y >> c;
        d[a][b] += c;
        d[a][y + 1] -= c;
        d[x + 1][b] -= c;
        d[x + 1][y + 1] += c;
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}