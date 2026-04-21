#include "bits/stdc++.h"
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

int n, m;

void solve() {
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << -1 << endl;
        return;
    }
    if (n != 1 && m != 1) {
        cout << -1 << endl;
        return;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (i)
                cout << 1;
            else
                cout << 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}

int main() {
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
