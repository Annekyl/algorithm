#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[n], t = -1; // a:初始值，b:每次增长值 c:ai/bi上取整
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = (a[i] + b[i] - 1) / b[i];
        t = max(t, c[i]);
    }
    vector<int> sort_c_idx(n); // 排序后的c数组对应到原始c数组的下标
    iota(sort_c_idx.begin(), sort_c_idx.end(), 0);
    sort(sort_c_idx.begin(), sort_c_idx.end(),
         [&](int i, int j) { return c[i] < c[j]; });
    vector<int> sort_c(n); // 排序后的c数组
    for (int i = 0; i < n; i++)
        sort_c[i] = c[sort_c_idx[i]];
    vector<int> pre(n + 1, 0); // 排序后的c数组的前缀和
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + sort_c[i];

    auto calc = [&](int T) -> int {
        // 找到第一个大于等于T的位置，共有pos个人小于T
        int pos = lower_bound(sort_c.begin(), sort_c.end(), T) - sort_c.begin();
        return T * pos - pre[pos];
    };

    int l = 0, r = t + m;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (calc(mid) <= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    t = l; // 找到的最大的T
    int remain = m - calc(t);

    vector<int> active;
    for (int i = 0; i < n; i++) {
        if (c[i] <= t)
            active.push_back(i);
    }
    // 按优先级排序
    sort(active.begin(), active.end(), [&](int i, int j) {
        int mod_i = a[i] % b[i];
        int mod_j = a[j] % b[j];
        if (mod_i == 0 && mod_j == 0)
            return false;
        else if (mod_i != 0 && mod_j != 0) {
            return mod_i * b[j] < mod_j * b[i];
        } else {
            return mod_i != 0;
        }
    });

    // 分配天数
    vector<int> day(n, 0);
    for (int idx : active) {
        day[idx] = t - c[idx];
    }
    for (int i = 0; i < remain; i++) {
        day[active[i]]++;
    }

    int res = 1;
    for (int i = 0; i < n; i++) {
        int val = ((a[i] % mod) + ((b[i] % mod) * (day[i] % mod))) % mod;
        res = res * val % mod;
    }
    cout << res << endl;
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
