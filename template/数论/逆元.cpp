// 逆元
// AcWing 876. 快速幂求逆元
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, p;
int inv[N]; // 逆元

// 快速幂求逆元
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

// 扩展欧几里得求逆元
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (d != 1) return -1;
    return (x % m + m) % m;
}

// 线性递推求逆元 (p为质数)
void get_inv(int n, int p) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (p - p / i) * inv[p % i] % p;
}

int main() {
    scanf("%d%d", &n, &p);

    get_inv(n, p);

    while (n--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", inv[x]);
    }

    return 0;
}
