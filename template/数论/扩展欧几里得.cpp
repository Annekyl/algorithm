// 扩展欧几里得算法 (Extended Euclidean Algorithm)
// AcWing 876. 快速幂求逆元 / 875. 快速幂
// 在欧几里得算法基础上，额外求出 ax + by = gcd(a, b) 的一组整数解
// 应用：求解线性同余方程 ax ≡ c (mod m)、求模逆元

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

// 扩展欧几里得算法
// 求解 ax + by = gcd(a, b) 的一组整数解 (x, y)
// 返回值为 gcd(a, b)
// 递推关系：设 ax + by = g，bx' + (a mod b)y' = g
//           则 y' = x - (a/b) * y，x' = y
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
// 有解条件：gcd(a, b) | c
// 解法：先求 ax + by = gcd(a, b) 的解，再将 x, y 扩大 c/gcd(a,b) 倍
bool solve(ll a, ll b, ll c, ll &x, ll &y) {
    ll d = exgcd(a, b, x, y);
    if (c % d) return false; // 无解
    x *= c / d;
    y *= c / d;
    return true;
}

// 求解 ax ≡ 1 (mod m) 的逆元
// 等价于求 ax + my = 1 的整数解
// 逆元存在条件：gcd(a, m) = 1
ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (d != 1) return -1; // gcd(a, m) != 1，无逆元
    return (x % m + m) % m; // 确保结果为正
}

// 快速幂
// 计算 a^b mod p，时间复杂度 O(log b)
// 原理：将 b 二进制分解，逐位处理
ll qmi(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;  // 当前位为 1，累乘
        a = a * a % p;                  // 底数平方
        b >>= 1;                        // 右移一位
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
