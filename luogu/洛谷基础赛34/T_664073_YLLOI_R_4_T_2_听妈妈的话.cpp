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

int n, t;

void solve() {
    cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int mx = max(a[i], a[i - 1]);
        if (mx < t)
            sum += t - mx;
    }
    cout << sum << endl;
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
