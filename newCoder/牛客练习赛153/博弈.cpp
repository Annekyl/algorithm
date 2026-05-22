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
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1)
            odd++;
        else
            even++;
    }
    if (odd > even) {
        cout << "Alice" << endl;
        return;
    }

    int mx1 = 0, cur1 = 0, mx2 = 0, cur2 = 0; // 1为奇数位置翻转,2为偶数位置翻转
    for (int i = 1; i <= n; i++) {
        int val = (a[i] & 1) ? -1 : 1;
        if (i & 1) {
            // 翻转奇数位置
            cur1 = max(cur1 + val, val);
            mx1 = max(mx1, cur1);
        } else {
            // 翻转偶数位置
            cur2 = max(cur2 + val, val);
            mx2 = max(mx2, cur2);
        }
    }
    int mx = max(mx1, mx2);
    if (odd + mx > even - mx) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
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
