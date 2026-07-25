#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vi cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > n)
            break;
        cnt[a[i]]++;
    }
    int mod = a[n - 1] + 1;
    // for (int i = 0; i <= n; i++)
    //     cout << cnt[i] << ' ';
    // cout << endl;

    int mx = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mx = i;
            break;
        }
    }
    mx = max(mx, mod);
    // if (mx <= 0) {
    //     cout << 1 << endl;
    //     return;
    // }
    // cout << mx << endl;

    int ans = 1;
    int idx = 0;
    while (1) {
        if (cnt[idx] > 0) {
            cnt[idx]--;
            ans++;
            idx = (idx + 1) % mx;
        } else {
            break;
        }
    }
    cout << ans << endl;
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