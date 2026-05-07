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
    int t, h, u;
    cin >> t >> h >> u;
    int ans = 0;
    if (t > 0 && u > 0) {
        int mx = min(t, u);
        t -= mx;
        u -= mx;
        ans += 4 * mx;
    }
    if (t > 0 && h > 0) {
        if (t >= h * 2) {
            // 会用完h
            ans += 7 * h;
            t -= h * 2;
            h = 0;
        } else {
            // 会用完t
            if (t % 2) {
                // t为奇数个时
                ans += 7 * (t / 2) + 5;
                h -= t / 2 + 1;
                t = 0;
            } else {
                ans += 7 * t / 2;
                h -= t / 2;
                t = 0;
            }
        }
    }
    if (t > 0) {
        ans += 3 * t - (t - 1);	// ⚠️t也可以叠放
        t = 0;
    }
    ans += 3 * (t + h + u);
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
