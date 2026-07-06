// 中国剩余定理 (CRT)
// 扩展中国剩余定理 (EXCRT)
// AcWing 204. 表达整数的奇怪方式
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

// 扩展欧几里得
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 扩展中国剩余定理
// 求解 x ≡ a1 (mod m1), x ≡ a2 (mod m2), ...
ll excrt(ll a1, ll m1, ll a2, ll m2) {
    ll x, y;
    ll d = exgcd(m1, m2, x, y);
    if ((a2 - a1) % d) return -1;
    ll lcm = m1 / d * m2;
    ll res = (a1 + m1 * ((a2 - a1) / d % (m2 / d) * x % (m2 / d))) % lcm;
    return (res % lcm + lcm) % lcm;
}

// 中国剩余定理 (模数两两互质)
ll crt(ll a[], ll m[], int n) {
    ll M = 1;
    for (int i = 0; i < n; i++) M *= m[i];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll Mi = M / m[i];
        ll ti;
        exgcd(Mi, m[i], ti, *(ll *)0);
        res = (res + a[i] * Mi % M * ti % M) % M;
    }
    return (res % M + M) % M;
}

int main() {
    int n;
    scanf("%d", &n);

    ll a1, m1, a2, m2;
    scanf("%lld%lld", &a1, &m1);

    bool flag = true;
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &a2, &m2);
        ll res = excrt(a1, m1, a2, m2);
        if (res == -1) {
            flag = false;
            break;
        }
        a1 = res;
        m1 = m1 / __gcd(m1, m2) * m2;
    }

    if (flag) printf("%lld\n", a1);
    else printf("-1\n");

    return 0;
}
