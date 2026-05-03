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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (stk.size()) {
                cout << "No" << endl;
                return;
            }
        } else {
            if (stk.empty() || a[i] > stk.top()) {
                stk.push(a[i]);
            }
        }
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
