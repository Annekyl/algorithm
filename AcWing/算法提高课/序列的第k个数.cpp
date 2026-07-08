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
constexpr int mod = 200907;
const int N = 1e5 + 10;

int qmi(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (b - a == c - b) {
        // 等差数列
        int d = b - a;
        int ans = (a + (k - 1) * d) % mod;
        cout << ans << endl;
    } else {
        // 等比数列
        int q = b / a;
        int ans = qmi(q, k - 1, mod) * a % mod;
        cout << ans << endl;
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
