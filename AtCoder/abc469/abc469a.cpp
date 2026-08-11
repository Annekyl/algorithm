#include "bits/stdc++.h"
#include <bits/extc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

// 类似 set<int>，支持 order statistics
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// 类似 map<int, int>
typedef tree<int, int, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;

// 允许重复元素的 "multiset"（用 pair 去重）
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
// 插入时用 t.insert({val, unique_id})

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << n - k + 1 << endl;
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
