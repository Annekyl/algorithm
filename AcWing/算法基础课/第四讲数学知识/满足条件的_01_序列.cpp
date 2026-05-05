#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

int n;

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;

    int ans = 1;
    int a = 2 * n, b = n;
    FOR(i, a - b + 1, a) ans = ans * i % mod;
    FOR(i, 1, b) ans = ans * qmi(i, mod - 2, mod) % mod;
    // FOR(i, 1, a - b) ans = ans * qmi(i, mod - 2, mod) % mod;
    ans = ans * qmi(n + 1, mod - 2, mod) % mod;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}