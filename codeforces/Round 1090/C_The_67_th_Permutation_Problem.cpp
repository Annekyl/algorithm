#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 3 + 1);
    int mx = n * 3;
    for (int i = 0; i < n; i++) {
        a[i * 3] = i + 1;
        a[i * 3 + 1] = mx - i * 2 - 1;
        a[i * 3 + 2] = mx - i * 2;
    }
    for (int i = 0; i < n * 3; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
