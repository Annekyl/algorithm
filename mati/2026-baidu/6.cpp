#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (c[i] == 1 && b[i] > 0 && a[i] == 0) {
            ans += 2;
        } else
            ans += 1;
    }
    // suc=!suc;
    if (ans % 2 != 0)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}