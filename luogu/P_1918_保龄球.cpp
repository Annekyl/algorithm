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
    vector<pii> a(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i - 1] = {x, i};
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        pii temp = {x, -1};
        int pos = lower_bound(a.begin(), a.end(), temp) - a.begin();
        // cout << pos << ' ';
        if (pos < n && a[pos].first == x)
            cout << a[pos].second << endl;
        else
            cout << 0 << endl;
    }
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
