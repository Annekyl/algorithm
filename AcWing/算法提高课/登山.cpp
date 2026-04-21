#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int up[n + 1], down[n + 1];
    memset(up, 0, sizeof up);
    memset(down, 0, sizeof down);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        up[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i])
                up[i] = max(up[i], up[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        down[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[j] < a[i])
                down[i] = max(down[i], down[j] + 1);
        }
        ans = max(ans, up[i] + down[i] - 1);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << up[i] << " " << down[i] << endl;
    // }

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
