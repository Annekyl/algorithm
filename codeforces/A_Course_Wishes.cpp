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
    vi sz(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> sz[i];
    vi a(n + 1);
    vi g[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
        sum += k + 1 - a[i];
    }
    if (sum > 1000) {
        cout << -1 << endl;
        return;
    }
    cout << sum << endl;
    for (int i = k; i >= 1; i--) {
        int cnt = k + 1 - i;
        for (int x : g[i]) {
            for (int _ = 0; _ < cnt; _++)
                cout << x << ' ';
        }
    }
    cout << endl;
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
