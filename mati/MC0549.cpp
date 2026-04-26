#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 10007;
constexpr int N = 1e5 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;

    while (m--) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(a.begin(), a.end(), l) - a.begin();
        int right = upper_bound(a.begin(), a.end(), r) - a.begin();
        // cout << left << " " << n - right << endl;
        ans = (ans + left + n - right) % mod;
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