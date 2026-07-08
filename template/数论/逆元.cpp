// 逆元 (Modular Inverse)
// AcWing 876. 快速幂求逆元
// 给定 n 组 a, p，求 a 模 p 的逆元，p 为质数
// 逆元定义：若 a * x ≡ 1 (mod p)，则 x 为 a 模 p 的逆元，记作 a^(-1)
// 当 p 为质数时，a 的逆元为 a^(p-2) (费马小定理)
// 时间复杂度：O(log p)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, p;
int inv[N]; // inv[i] 存储 i 模 p 的逆元

// 方法一：快速幂求逆元 (费马小定理)
// a^(p-2) ≡ a^(-1) (mod p)，前提 p 为质数且 gcd(a, p) = 1
// 快速幂：将指数二进制分解，O(log b) 计算 a^b mod p
ll qmi(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;  // 当前位为1，累乘
        a = a * a % p;                  // 底数平方
        b >>= 1;                        // 右移一位
    }
    return res;
}

// 方法二：扩展欧几里得求逆元
// 解方程 ax + my = 1，则 x 即为 a 模 m 的逆元
// 适用于 gcd(a, m) = 1 的情况，不要求 m 为质数
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
    if (d != 1) return -1;  // gcd(a, m) != 1，无逆元
    return (x % m + m) % m; // 确保结果为正
}

// 方法三：线性递推求逆元 (p 为质数)
// 递推公式：inv[i] = (p - p / i) * inv[p % i] mod p
// 时间复杂度：O(n)，可预处理出 [1, n] 内所有数的逆元
// 推导：设 p = k * i + r，则 k * i + r ≡ 0 (mod p)
//       两边同除以 i * r，得 inv[i] ≡ -k * inv[r] ≡ (p - k) * inv[r]
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
