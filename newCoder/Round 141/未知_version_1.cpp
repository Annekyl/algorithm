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

int n;

void solve() {
    // cin >> n;
    int x, y;
    cin >> x >> y;
    if (x > y)
        cout << 0 << endl;
    else {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((y >> i) & 1) {
                ans += (1 << i);
                if ((x ^ ans) > (y ^ ans))
                    break;
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
