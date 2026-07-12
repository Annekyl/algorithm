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
constexpr int mod = 1e9 + 7;
const int N = 1e6 + 10;

int prime[N], cnt;
int st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] * i <= n; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    get_prime(n);
    // vector<pii> a;
    int ans = 1;
    // 勒让德定理，求n!的质因子对应指数
    for (int i = 0; i < cnt; i++) {
        int p = prime[i];
        int temp = n, c = 0;
        while (temp) {
            c += temp / p;
            temp /= p;
        }
        // a.push_back({p, c});
        ans = ans * ((c * 2 + 1) % mod) % mod;
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
