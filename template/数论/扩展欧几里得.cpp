// 扩展欧几里得算法
// AcWing 876. 快速幂求逆元 / 875. 快速幂
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

// 扩展欧几里得算法
// 求解 ax + by = gcd(a, b) 的一组整数解
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 求解 ax + by = c 的整数解
// 有解条件: gcd(a, b) | c
bool solve(ll a, ll b, ll c, ll &x, ll &y) {
    ll d = exgcd(a, b, x, y);
    if (c % d) return false;
    x *= c / d;
    y *= c / d;
    return true;
}

// 求解 ax ≡ 1 (mod m) 的逆元
ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (d != 1) return -1; // 无逆元
    return (x % m + m) % m;
}

// 快速幂
ll qmi(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll inv = mod_inverse(a, b);
        if (inv == -1) printf("impossible\n");
        else printf("%lld\n", (inv % b + b) % b);
    }

    return 0;
}
