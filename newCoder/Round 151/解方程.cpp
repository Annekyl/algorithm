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
const int N = 2e5 + 10;

int freq[N];   // 每个数出现的频率
int cnt[N];    // 每个数的倍数出现的频率
int mx_gcd[N]; // 当选择k个数时最大的gcd

int fact[N], inv[N];

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

void precompute() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[N - 1] = qmi(fact[N - 1], mod - 2, mod);
    for (int i = N - 2; i > 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

int cr(int n, int m) {
    int res = fact[n] * inv[m] % mod * inv[n - m] % mod;
    return res;
}

void solve() {
    precompute();
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            cnt[i] += freq[j];
        }
    }

    for (int i = 1; i <= mx; i++) {
        if (cnt[i] > 0)
            mx_gcd[cnt[i]] = max(mx_gcd[cnt[i]], i);
    }

    // 从后向前进行更新
    for (int i = n; i >= 0; i--) {
        mx_gcd[i] = max(mx_gcd[i], mx_gcd[i + 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int g = mx_gcd[k];
        int c = cnt[g];

        cout << cr(c, k) << endl;
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
