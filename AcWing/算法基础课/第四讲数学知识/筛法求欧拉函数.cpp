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
constexpr int N = 1e6 + 10;

int n;
int phi[N];
int prime[N], v[N], m;

void euler() {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            prime[++m] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; prime[j] <= n / i; j++) {
            int t = prime[j] * i;
            v[t] = 1;
            if (i % prime[j] == 0) {
                phi[t] = phi[i] * prime[j];
                break;
            }
            phi[t] = phi[i] * (prime[j] - 1);
        }
    }
}

void solve() {
    cin >> n;

    euler();

    int ans = 0;
    FOR(i, 1, n) ans += phi[i];
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