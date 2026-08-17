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
const int N = 1e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    vi mp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    vi *p = &a;
    vi *p2 = &mp;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            vector<int>& cur = *p;
            vector<int>& mpp = *p2;
            int x, y;
            cin >> x >> y;
            swap(cur[x], cur[y]);
            swap(mpp[cur[x]], mpp[cur[y]]);
        } else {
            vi *temp = p;
            p = p2;
            p2 = temp;
        }
        // auto res = *p;
        // for (int i = 1; i <= n; i++)
        //     cout << res[i] << ' ';
        // cout << endl;
    }
    auto res = *p;
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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
