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

int n, m;

void solve() {
    cin >> n >> m;
    if (n != m * 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) {
        if (i != m)
            cout << i << " " << i + m << endl;
        cout << i << " " << i + 1 << endl;
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
