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

void solve() {
    int n;
    cin >> n;
    int g[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i)
                g[i][j] = 1;
            else
                g[i][j] = g[i - 1][j - 1] + g[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << g[i][j] << ' ';
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
