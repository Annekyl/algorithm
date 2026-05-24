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
    int a[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    string s;
    cin >> s;
    s = " " + s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }

    int sum0 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            sum0 += a[i];
        }
    }
    if (sum * cnt0 % n) {
        cout << -1 << endl;
    } else {
        int val = sum * cnt0 / n;
        int ans = abs(sum0 - val);
        cout << ans << endl;
    }
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
