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

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> f(n + 1, 0);
    int best_even = -(1 << 30), best_odd = -(1 << 30);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (a[i] % 2 == 0) {
            f[i] = max(f[i], a[i] + best_even);
            best_even = max(best_even, f[i - 1] + a[i]);
        } else {
            f[i] = max(f[i], a[i] + best_odd);
            best_odd = max(best_odd, f[i - 1] + a[i]);
        }
    }
    cout << f[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
