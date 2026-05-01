#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int t, x;
    vector<pii> a;
    cin >> t >> x;
    for (int i = 0; i <= t; i++) {
        int m;
        cin >> m;
        if (a.empty() || abs(a.back().second - m) >= x)
            a.push_back({i, m});
    }
    for (auto [a, b] : a)
        cout << a << ' ' << b << endl;
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
