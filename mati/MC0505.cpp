#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, q;

void solve() {
    cin >> n >> q;
    int a[n + 1];
    int s[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++) {
                a[i] += x;
            }
        } else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++) {
                if (a[i] > x)
                    a[i] = x;
            }
        } else {
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (int i = l; i <= r; i++)
                res += a[i];
            cout << res << endl;
        }
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