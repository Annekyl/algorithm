#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 3200;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //     sum ^= a[i];
    // }
    // cout << sum << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, a[i] ^ a[j]);
        }
    }
    cout << ans << endl;
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
