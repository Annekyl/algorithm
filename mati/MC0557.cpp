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
    int l, r, up, down;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            l = x;
            r = x;
            up = y;
            down = y;
        } else {
            l = min(l, x);
            r = max(r, x);
            up = max(up, y);
            down = min(down, y);
        }
    }
    int ans = (r - l) * (up - down);
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