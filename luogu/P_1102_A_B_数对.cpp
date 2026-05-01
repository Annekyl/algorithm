#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int n, c;
    cin >> n >> c;

    // cout << n << ' ' << c << endl;
    // exit(0);

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= c)
            break;
        // exit(0);
        int target = a[i] - c;
        int cnt1 = lower_bound(a.begin(), a.end(), target) - a.begin();
        int cnt2 = upper_bound(a.begin(), a.end(), target) - a.begin();
        // cout << cnt2 - cnt1 << endl;
        ans += cnt2 - cnt1;
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
