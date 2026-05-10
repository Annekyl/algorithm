#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, pii> mp;
    bool suc = true;
    while (q--) {
        int p, l, r;
        cin >> p >> l >> r;
        if (mp.find(p) == mp.end()) {
            mp[p] = {l, r};
        } else {
            auto [l1, r1] = mp[p];
            if (l1 > r || r1 < l) {
                suc = false;
                continue;
            }
            l = max(l, l1);
            r = min(r, r1);
            mp[p] = {l, r};
        }
    }

    if (!suc) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (auto [idx, temp] : mp) {
        auto [l, r] = temp;
        if (a[idx] >= l && a[idx] <= r)
            continue;
        if (a[idx] > r) {
            ans += a[idx] - r;
        } else {
            ans += l - a[idx];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
