#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 5e5 + 10;

int prime[N], cnt;
int spf[N];

void euler() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            prime[++cnt] = i;
            spf[i] = i;
        }
        for (int j = 1; prime[j] * i < N; j++) {
            spf[prime[j] * i] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    euler();
    vi W(n + 1), C(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> W[i];
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    vi dp(n + 1, 1);
    vi mx1_val(10, 0), mx1_c(10);
    vi mx2_val(10, 0), mx2_c(10);
    for (int i = 1; i <= n; i++) {
        int w = W[i], c = C[i];
        // 对亮度c进行质因子分解
        vi primes;
        while (w > 1) {
            int p = spf[w];
            primes.push_back(p);
            while (w % p == 0)
                w /= p;
        }

        for (int p : primes) {
            if (mx1_c[p] != c) {
                dp[i] = max(dp[i], mx1_val[p] + 1);
            } else {
                dp[i] = max(dp[i], mx2_val[p] + 1);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}