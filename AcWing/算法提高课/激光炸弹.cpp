#include "bits/stdc++.h"
// #define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 5e3 + 10;

// int a[N][N];
int s[N][N];

void solve() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = 0;
    if (r > 5000) {
        ans = s[N - 1][N - 1];
    } else {
        for (int i = r; i < N; i++) {
            for (int j = r; j < N; j++) {
                int val = s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r];
                ans = max(ans, val);
            }
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
