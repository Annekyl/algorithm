// 中国剩余定理 (CRT) / 扩展中国剩余定理 (EXCRT)
// AcWing 204. 表达整数的奇怪方式
// 求解同余方程组 x ≡ a1 (mod m1), x ≡ a2 (mod m2), ...
// CRT：要求模数两两互质，构造法求解，时间复杂度 O(n)
// EXCRT：不要求模数互质，用扩展欧几里得逐步合并，时间复杂度 O(n log m)

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

// 扩展中国剩余定理 (EXCRT)
// 逐步合并两个同余方程：x ≡ a1 (mod m1), x ≡ a2 (mod m2)
// 合并方法：x = a1 + m1 * k，代入得 m1 * k ≡ a2 - a1 (mod m2)
//          用扩展欧几里得求解 k，然后得到新的 x 和 lcm(m1, m2)
// 返回 -1 表示无解
ll excrt(ll a1, ll m1, ll a2, ll m2) {
    ll x, y;
    ll d = exgcd(m1, m2, x, y);
    if ((a2 - a1) % d) return -1; // m1*k ≡ a2-a1 (mod m2) 无解
    ll lcm = m1 / d * m2;
    // 注意：x 可能为负，需要取模调整
    ll res = (a1 + m1 * ((a2 - a1) / d % (m2 / d) * x % (m2 / d))) % lcm;
    return (res % lcm + lcm) % lcm;
}

// 中国剩余定理 (CRT)
// 要求模数 m1, m2, ..., mn 两两互质
// 构造：M = m1 * m2 * ... * mn
//      Mi = M / mi
//      ti 是 Mi 模 mi 的逆元
//      x = (a1 * M1 * t1 + a2 * M2 * t2 + ... + an * Mn * tn) mod M
ll crt(ll a[], ll m[], int n) {
    ll M = 1;
    for (int i = 0; i < n; i++) M *= m[i];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll Mi = M / m[i];
        ll ti;
        exgcd(Mi, m[i], ti, *(ll *)0);
        // 注意：这里 ti 可能为负，乘法会溢出，需要取模
        res = (res + a[i] * Mi % M * ti % M) % M;
    }
    return (res % M + M) % M;
}

int main() {
    int n;
    scanf("%d", &n);

    ll a1, m1, a2, m2;
    scanf("%lld%lld", &a1, &m1);

    // 逐个合并同余方程
    bool flag = true;
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &a2, &m2);
        ll res = excrt(a1, m1, a2, m2);
        if (res == -1) {
            flag = false;
            break;
        }
        a1 = res;
        m1 = m1 / __gcd(m1, m2) * m2; // 更新模数为 lcm(m1, m2)
    }

    if (flag) printf("%lld\n", a1);
    else printf("-1\n");

    return 0;
}
