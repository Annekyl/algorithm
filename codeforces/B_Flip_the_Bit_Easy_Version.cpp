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
    int n, k;
    cin >> n >> k;
    vi a(n + 2);
    int idx;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> idx;

    vi f(n + 2);
    for (int i = 1; i <= n; i++) {
        f[i] = (a[i] != a[idx]);
    }

    int l = 0, r = 0;
    for (int i = 1; i <= idx; i++) {
        l += abs(f[i] - f[i - 1]);
    }
    for (int i = idx + 1; i <= n + 1; i++) {
        r += abs(f[i] - f[i - 1]);
    }
    cout << max(l, r) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
