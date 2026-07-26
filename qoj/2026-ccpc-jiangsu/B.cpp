#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int x;
    cin >> x;
    int ans = x;
    int st = sqrt(x) + 1;
    for (int i = st; i > 0; i--) {
        int a = i;
        if (x / (a + 1) - a >= ans) {
            break;
        }
        int bb[4] = {x / (a + 1), x / (a + 1) + 1, x / a - 1, x / a};
        for (int i = 0; i < 4; i++) {
            int b = bb[i];
            if (b < a)
                continue;
            int c = x - a * b;
            if (c < 0)
                continue;
            int mx = max({a, b, c});
            int mn = min({a, b, c});
            ans = min(ans, mx - mn);
        }
    }
    cout << ans << endl;
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