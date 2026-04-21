#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    vi a;
    a.push_back(0);
    int x;
    while (cin >> x)
        a.push_back(x);
    int n = a.size() - 1;
    vi f(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        mx = max(mx, f[i]);
    }
    cout << mx << endl;
    int cnt = 0;
    vi height;
    for (int i = 1; i <= n; i++) {
        bool suc = false;
        for (int j = 0; j < cnt; j++) {
            if (a[i] <= height[j]) {
                height[j] = a[i];
                suc = true;
                break;
            }
        }
        if (!suc) {
            height.push_back(a[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
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
