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

int sum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool suc = true;
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        int last = 0;
        while (a[i] > a[i + 1] && a[i] != last) {
            last = a[i];
            a[i] = sum(a[i]);
            ans++;
        }
        if (a[i] > a[i + 1]) {
            suc = false;
            break;
        }
    }
    if (!suc) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
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
