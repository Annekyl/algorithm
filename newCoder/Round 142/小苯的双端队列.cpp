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
    int st = 1, ed = n;
    bool suc = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == st)
            st++;
        else if (a[i] == ed)
            ed--;
        else
            suc = false;
    }
    if (suc)
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
