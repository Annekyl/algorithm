#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int res = gcd(x, y);
    bool suc = true;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int d = i - x;
        if (d % res != 0)
            suc = false;
    }
    if (suc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
