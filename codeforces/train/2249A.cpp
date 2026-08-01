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
    int l[n + 1], r[n + 1], u[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }
    for (int m = n; m >= 1; m--) {
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (l[i] <= cnt && cnt <= r[i] || u[i] <= (m - cnt + 1) &&
                (m - cnt + 1) <= v[i])
                continue;
            if (cnt == m) {
                cout << m << endl;
                return;
            }
            cnt++;
        }
    }
    cout << 0 << endl;
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
