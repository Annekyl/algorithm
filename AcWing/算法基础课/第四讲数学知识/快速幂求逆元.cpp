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
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int a, p;

void solve() {
    cin >> a >> p;
    if (a % p == 0) {
        cout << "impossible" << endl;
        return;
    }

    int mod = p;
    int ans = 1;
    p -= 2;
    while (p) {
        if (p & 1)
            ans = (ans * a) % mod;
        p >>= 1;
        a = (a * a) % mod;
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