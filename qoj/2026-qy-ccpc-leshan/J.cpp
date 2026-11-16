#include "bits/stdc++.h"
using namespace std;

#define int long long

void solve() {
    int k;
    cin >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    // 若至少有两种药物数量为 0，必然无法区分
    if (k >= 2 && a[2] == 0) {
        cout << -1 << '\n';
        return;
    }

    auto check = [&](int m) -> bool {
        int c = 0;
        int cur = 1; // C(m, 0)
        int sum = 1; // sum_{s=0}^{c} C(m, s)

        for (int j = 1; j <= k; ++j) {
            int limit = min(a[j], m);
            while (c < limit && sum < k) {
                ++c;
                cur = cur * (m - c + 1) / c;
                sum += cur;
            }
            if (sum < j) {
                return false;
            }
        }
        return true;
    };

    int l = 0, r = k - 1, ans = k - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}