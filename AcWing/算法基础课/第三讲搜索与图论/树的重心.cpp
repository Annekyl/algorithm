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
constexpr int N = 1e5 + 10;

int n;
vi g[N];
int deg[N];
int ans = INF;

void add(int x, int y) { g[x].push_back(y); }

int dfs(int x, int fa) {
    int sz = 1, max_sz = 0;
    for (auto &y : g[x]) {
        if (y == fa)
            continue;
        int child_sz = dfs(y, x);
        sz += child_sz;
        max_sz = max(max_sz, child_sz);
    }
    int fa_sz = n - sz;
    max_sz = max(max_sz, fa_sz);
    ans = min(ans, max_sz);
    return sz;
}

void solve() {
    cin >> n;
    FOR(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }

    dfs(1, -1);
    cout << ans;
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