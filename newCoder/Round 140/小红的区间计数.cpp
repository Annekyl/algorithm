#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'
#define forr(i, l, r) for (int i = (l); i <= (r); ++i)
#define ref(i, l, r) for (int i = (l); i >= (r); --i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

int n, m;
vi a(N);

void solve() {
    int a, b, c, l, r;
    cin >> a >> b >> c >> l >> r;
    int ans = 0;
    forr(i, l, r) {
        int x = i;
        if (x == a)
            continue;
        if (x == b)
            continue;
        if (x == c)
            continue;
        ans++;
    }
    cout << ans;
}

signed main() {
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
