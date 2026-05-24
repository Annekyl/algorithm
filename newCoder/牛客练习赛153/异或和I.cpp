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
const int N = 1e5 + 10;

int max_v = 4096;

void solve() {
    int n, mod;
    cin >> n >> mod;
    int a[n + 1], s[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    int f[n + 1][max_v]; // 前i个数中最后一段异或和为v时的最大段数
    int g[n + 1][max_v]; // 对应的方案数
    int max_f[n + 1][max_v];
    int max_g[n + 1][max_v];
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
