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

void solve(int n) {
    // int n;
    // cin >> n;

    int cnt = log2(n);

    int ans = cnt;
    if (cnt >= 4) {
        ans = (cnt - 3) * 2 + 3;
    }
    if ((1 << cnt) == n) {
        cout << ans;
    } else {
        cout << ans + 1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t = 1;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    for (int i = 3; i <= 100; i++) {
        solve(i);
        cout << ' ';
        if (i % 10 == 0)
            cout << endl;
    }
    return 0;
}