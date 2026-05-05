#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 210;

int n, m, q;
int d[N][N];

void solve() {
    cin >> n >> m >> q;

    memset(d, 0x3f, sizeof d);
    FOR(i, 1, n) d[i][i] = 0;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2) {
            cout << "impossible" << endl;
        } else {
            cout << d[x][y] << endl;
        }
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