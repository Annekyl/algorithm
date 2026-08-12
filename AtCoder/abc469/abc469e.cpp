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
    int n, k;
    cin >> n >> k;
    string s;	
    cin >> s;
    s = " " + s;

    vi cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        if (s[i] == 'o')
            cnt[i]++;
    }

    auto check = [&](double mid) -> bool {
        vector<double> a(n + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'o') {
                a[i] = a[i - 1] + 1.0 - mid;
            } else {
                a[i] = a[i - 1] - mid;
            }
        }

        int mx_idx = 0; // 最大的合法前缀和下标
        double mn_a = 0;	// 合法前缀和的最小值
        for (int r = 1; r <= n; r++) {
            if (cnt[r] >= k) {
                int target = cnt[r] - k;

                // 更新mx_idx和mn_a
                while (cnt[mx_idx + 1] <= target) {
                    mx_idx++;
                    mn_a = min(mn_a, a[mx_idx]);
                }

                if (a[r] >= mn_a)
                    return true;
            }
        }
        return false;
    };

    double l = 0, r = 1.0;
    double eps = 1e-8;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << r << endl;
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
