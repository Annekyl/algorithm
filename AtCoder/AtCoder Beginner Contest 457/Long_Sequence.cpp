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
    int n, k;
    cin >> n >> k;
	k--;
    vi a[n + 1];
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        while (l--) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        int x, sz = a[i].size();
        cin >> x;
        if (x * sz <= k) {	// ⚠️小于等于，不是小于
            k -= x * sz;
        } else {
            k %= sz;
            cout << a[i][k] << endl;
            return;
        }
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
