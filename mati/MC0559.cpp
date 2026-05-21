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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++) {
            int dx = abs(a[i].first - a[j].first);
            int dy = abs(a[i].second - a[j].second);
            mx = max(mx, dx + dy);
        }
        ans = min(ans, mx);
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