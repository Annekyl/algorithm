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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o')
            continue;
        if ((i - 1 < 0 || s[i - 1] == 'x') && (i + 1 >= n || s[i + 1] == 'x'))
            ans++;
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
