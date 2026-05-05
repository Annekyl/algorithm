#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;
constexpr int MOD = 9901;

int a, b;
unordered_map<int, int> fac;

// 快速幂
ll quick_pow(ll x, ll y, ll mod) {
    ll ans = 1;
    x %= mod;
    while (y) {
        if (y & 1) {
            ans = (ans * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

// 分解质因数
void factor(int x) {
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            fac[i]++;
            x /= i;
        }
    }

    if (x > 1)
        fac[x]++;
}

// 等比数列求和，分治法
ll geometric_sum(ll p, ll n) {
    // p:公比 n:最高项的幂

    if (n == 0)
        return 1;
    if (n == 1)
        return (1 + p) % MOD;

    if (n % 2 == 1) {
        return (1 + p) * geometric_sum(p * p % MOD, (n - 1) / 2) % MOD;
    } else {
        return (1 + p * geometric_sum(p, n - 1)) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (b == 0) {
        cout << 1 << endl;
        return 0;
    }

    factor(a);

    ll res = 1;
    for (auto &[p, cnt] : fac) {
        ll exponent = (ll)cnt * b;
        ll sum = geometric_sum(p, exponent);
        res = (res * sum) % MOD;
    }
    cout << res << endl;
    return 0;
}