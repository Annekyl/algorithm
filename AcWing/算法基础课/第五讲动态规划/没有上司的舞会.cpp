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
constexpr int N = 6010;

int n;
int w[N];
vi g[N];
int f[N][2];
bool has_father[N];

void dfs(int x) {
    f[x][1] = w[x];
    for (auto &y : g[x]) {
        dfs(y);
        f[x][0] += max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n - 1) {
        int x, y;
        cin >> y >> x;
        g[x].push_back(y);
        has_father[y] = 1;
    }

    int root;
    FOR(i, 1, n) {
        if (has_father[i] == 0) {
            root = i;
            break;
        }
    }

    dfs(root);
    int ans = max(f[root][0], f[root][1]);
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