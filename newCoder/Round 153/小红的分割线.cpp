#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[i] - x[j], dy = y[i] - y[j];
            int l = 0, r = 0;
            for (int k = 0; k < n; k++) {
                int d = (x[k] - x[i]) * dy - (y[k] - y[i]) * dx;
                if (d > 0)
                    l++;
                else if (d < 0)
                    r++;
            }
            if (l == r)
                res++;
        }
    }
    cout << res << endl;
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
