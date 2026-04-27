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
    // cout << 1e9 * 1e9 << endl;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    // 存在大于等于2个1
    if (mp.count(1) >= 2) {
        cout << "YES" << endl;
        return;
    }

    // 存在一个1
    if (mp.count(1) == 1) {
        for (auto [x, cnt] : mp) {
            if (cnt >= 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    sort(a.begin(), a.end());
    int mx = a[n - 1];
    for (auto [x, cnt] : mp) {
        if (x == 1)
            continue;
        int res = x * x;
        int p = 2;
        while (res <= mx) {
            if (mp.count(res) > 0 && mp.count(p) > 0) {
                cout << "YES" << endl;
                return;
            }
            p++;
            res *= x;
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
