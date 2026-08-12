#include "bits/stdc++.h"
// #include <bits/extc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// typedef tree<int, int, less<int>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_map;

// typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e6 + 10;

int pos[N];
int fa[N];

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return false;
    fa[fx] = fy;
    return true;
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
        fa[i] = i;
        mx = max(mx, x);
    }

    int ans = 0;
    int cnt = 0; // 当前合并的边数
    for (int g = mx; g >= 1; g--) {
        int first = 0;
        for (int j = g; j <= mx; j += g) {
            if (pos[j]) {
                if (!first) // 第一次遇到，记录下标
                    first = pos[j];
                else { // 并查集合并
                    if (merge(first, pos[j])) {
                        cnt++;
                        ans += g;
                    }
                }
            }
        }

        if (cnt == n - 1)
            break;
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
