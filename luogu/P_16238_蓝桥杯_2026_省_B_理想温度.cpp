#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n + 1], b[n + 1], d[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        d[i] = a[i] - b[i];
    }
    int zero = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0)
            zero++;
    }
	// debug(zero);

    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            map<int, int> mp;
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (d[i] == 0)
                    zero++;
                else
                    mp[d[i]]++;
            }
            for (auto [num, c] : mp) {
                ans = max(ans, c + zero - cnt);
            }
        }
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
