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
    vi h(n + 1), fa(n + 1), ans(n + 1), w(n + 1);
    vi g[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }

    for (int i = 2; i <= n; i++) {
        cin >> w[i];
    }

    int sum = 0;
    // dfs返回充满x所在的系统所需要的注水量,sum为当前的系统总注水量
    function<void(int)> dfs = [&](int x) {
        int cur = 0;
        for (int y : g[x]) {
            sum += w[y] - cur;
            cur = w[y];
            dfs(y);
        }
        sum += h[x] - cur;
        ans[x] = sum;
    };

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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
