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
    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "NO" << endl;
        return;
    }
    int avg = sum / n;

    auto check = [&](int st) -> bool {
        int cur = st;
        for (int i = 0; i < n; i++) {
            cur += a[i] - avg;
            if (cur < 0 || cur > 1) {
                return false;
            } else if (cur == 1 && a[i] == 0) {
                return false;
            }
        }
        return cur == st;
    };

    if (check(0) || check(1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
