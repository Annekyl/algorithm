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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    int mn = (1 + d) * n;
    if (m < mn)
        cout << -1 << endl;
    else {
        int sum = 0;
        int x1 = m - mn;
        sum += min(x1, n);
        m -= mn + sum;
        if (m > 0) {
            sum += m / (d + 1);
        }
        cout << sum << endl;
    }
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
