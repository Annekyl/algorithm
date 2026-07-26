#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        // cout << a[i].first << ' ' << a[i].second << endl;
    }

    auto check = [&](int t) -> bool {
        vector<pii> qujian;
        for (auto [st, pos] : a) {
            int len = t - st;
            if (len < 0)
                continue;
            qujian.push_back({pos - len, pos + len});
            // cout << qujian.back().first << ' ' << qujian.back().second <<
            // endl;
        }
        sort(qujian.begin(), qujian.end());
        if (!qujian.size())
            return false;
        if (qujian[0].first > 0)
            return false;
        int r = qujian[0].second;
        for (int i = 1; i < qujian.size(); i++) {
            if (qujian[i].first <= r + 1) {
                r = max(r, qujian[i].second);
            } else {
                return false;
            }
        }
        return r >= k;
    };

    int l = 0, r = 1e18;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
        // cout << mid << ' ' << l << ' ' << r << endl;
    }
    cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}