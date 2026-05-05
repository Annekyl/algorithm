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
constexpr int N = 20;

int n;
int g[N][N];
int f[1 << N][N];

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1) { cin >> g[i][j]; }
    }

    // FOR(i, 0, n - 1) {
    //     FOR(j, 0, n - 1) { cout << g[i][j] << " "; }
    //     cout << endl;
    // }

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    // 遍历所有状态
    FOR(i, 0, (1 << n) - 1) {
        // 遍历该状态的点
        FOR(j, 0, n - 1) {
            if ((i >> j) & 1) {
                // 状态转移
                FOR(k, 0, n - 1) {
                    if (((i - (1 << j)) >> k) & 1) {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + g[k][j]);
                    }
                }
            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl;
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