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
constexpr int N = 5e4 + 10;

int n, k;

int fa[N],
    d[N]; // fa:存父节点编号 d:存与父节点的关系 0-同类 1-吃父节点 2-被父节点吃

void init() {
    FOR(i, 1, n) {
        fa[i] = i;
        d[i] = 0;
    }
}

int find(int x) {
    if (fa[x] == x)
        return x;
    int root = find(fa[x]);
    d[x] = (d[x] + d[fa[x]]) % 3;
    fa[x] = root;
    return fa[x];
}

void solve() {
    cin >> n >> k;
    init();
    int ans = 0;
    FOR(i, 1, k) {
        int st, x, y;
        cin >> st >> x >> y;

        // 超出范围
        if (x > n || y > n) {
            ans++;
            continue;
        }

        // 自己吃自己
        if (x == y && st == 2) {
            ans++;
            continue;
        }

        int fx = find(x), fy = find(y);
        if (st == 1) {
            // x和y是同类
            if (fx == fy && (d[x] - d[y] + 3) % 3 != 0) {
                ans++;
            } else if (fx != fy) {
                fa[fx] = fy;
                d[fx] = d[y] - d[x];
            }
        } else {
            // x吃y
            if (fx == fy && (d[x] - d[y] + 3) % 3 != 1) {
                ans++;
            } else if (fx != fy) {
                fa[fx] = fy;
                d[fx] = d[y] - d[x] + 1;
            }
        }
    }
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