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
constexpr int mod = 9901;
const int N = 1e5 + 10;

vector<pii> prime;

int qmi(int a, int b, int p) {
    int res = 1;
    a = a % p;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) {
                a /= i;
                cnt++;
            }
            prime.push_back({i, cnt * b});
        }
    }

    // ⚠️处理质因数分解剩下的最后一个大于 sqrt(A) 的质因子
    if (a > 1)
        prime.push_back({a, b});

    int ans = 1;
    for (auto [p, cnt] : prime) {
        // cout << p << ' ' << cnt << endl;
        if ((p - 1) % mod == 0) {
            ans = ans * ((cnt + 1) % mod) % mod;
        } else {
            int up = (qmi(p, cnt + 1, mod) - 1 + mod) % mod;
            int down = qmi(p - 1, mod - 2, mod);
            ans = ans * up % mod * down % mod;
        }
    }
    cout << ans << endl;
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
