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
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c(n + 1);
    int sum_b = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    auto check = [&](int mx) -> bool {
        vi cap(n + 1, 0);
        int sum_cap = 0; // 容量
        for (int i = 1; i <= n; i++) {
            // ⚠️cap没必要超过sum_b,否则累加后可能超过long long
            cap[i] = min(mx / c[i], sum_b);
            sum_cap += cap[i];
        }

        if (sum_cap < sum_b)
            return false;
        for (int i = 1; i <= n; i++) {
            if (sum_cap - cap[a[i]] < b[i])
                return false;
        }
        return true;
    };

    int l = 0, r = INF;
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int ans = r;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}