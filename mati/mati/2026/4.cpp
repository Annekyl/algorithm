#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    if (n % 3 != 0) {
        int ans = (n - 1) / 2 * n;
        cout << ans << endl;
    } else {
        int ans = (n - 1) / 2 * n;
        ans -= n / 3 * 2;
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}