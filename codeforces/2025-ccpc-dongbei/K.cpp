#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int g[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    }
    vi cnt(m + 1, 0);
    for (int j = 1; j <= m; j++) {
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if (g[i][j] == g[1][j])
                len++;
            else
                break;
        }
        cnt[g[1][j]] = max(cnt[g[1][j]], len);
    }
    int sub = 0;
    for (int i = 1; i <= m; i++)
        sub += cnt[i];
    int ans = n * m - sub;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}