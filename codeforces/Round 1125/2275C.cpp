#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
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
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n - 4; i++) {
        int val = a[i] + a[i + 2] - a[i + 4];
        int cnt = mp[val];
        if (i >= 3) {
            if (a[i - 2] + a[i] - a[i + 2] == val)
                cnt--;
        }
        if (i >= 5) {
            if (a[i - 4] + a[i - 2] - a[i] == val)
                cnt--;
        }
        ans += cnt;
        mp[val]++;
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
