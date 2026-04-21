#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef vector<int> vi;

const int N = 1e5 + 10;

int n;
vi a(N, 0);

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1)
            ans++;
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}