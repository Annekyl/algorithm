#include "bits/stdc++.h"
#define int long long // 使用 long long 防止基础数据溢出
#define endl '\n'

using namespace std;

const int N = 1e5 + 10;

int n;
int m[N], a[N]; // m[i] 是模数，a[i] 是余数

/**
 * 龟速乘 (Binary Multiplication)
 * 目的：计算 (a * b) % m，防止直接相乘导致 long long 溢出
 * 原理：类似于快速幂，将乘法拆解为加法
 * 注意：在现代竞赛中，也可以直接使用 __int128 替代
 */
int mul(int a, int b, int m) {
    int res = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

/**
 * 扩展欧几里得算法 (EXGCD)
 * 求解 ax + by = gcd(a, b)
 * 返回值是 a 和 b 的最大公约数 g
 */
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

/**
 * 扩展中国剩余定理 (EXCRT)
 * 核心思想：每次合并两个同余方程，直到剩下最后一个
 * 方程1：x ≡ a1 (mod m1)  => x = k1*m1 + a1
 * 方程2：x ≡ a2 (mod m2)  => x = k2*m2 + a2
 * 合并得：k1*m1 + a1 = k2*m2 + a2  =>  k1*m1 - k2*m2 = a2 - a1
 * 这变成了一个形如 Ax + By = C 的线性同余方程，可用 EXGCD 求解 k1
 */
int excrt() {
    int x, y;
    int m1 = m[0], a1 = a[0]; // 初始合并结果为第一个方程
    int ans = (a1 % m1 + m1) % m1;

    for (int i = 1; i < n; i++) {
        int m2 = m[i], a2 = a[i];

        // 目标方程：m1 * x + m2 * y = (a2 - a1)
        int A = m1, B = m2, C = (a2 - a1 % m2 + m2) % m2;

        int g = exgcd(A, B, x, y);

        // 如果 (a2 - a1) 不能被 gcd(m1, m2) 整除，则方程组无解
        if (C % g != 0)
            return -1;

        // 求解当前的线性同余方程，注意要在 mod (m2/g) 的范围内求解 x 以防溢出
        // 这里的 x 对应公式中的 k1
        x = mul(x, C / g, m2 / g);

        // 计算新的总余数 ans' = a1 + x * m1
        ans = a1 + x * m1;

        // 更新当前的最小公倍数 (新的模数) m1' = lcm(m1, m2)
        m1 = m2 / g * m1;

        // 保持结果在非负范围内
        ans = (ans % m1 + m1) % m1;
        a1 = ans; // 更新 a1 为当前合并后的总余数
    }
    return ans;
}

void solve() {
    if (!(cin >> n))
        return;
    for (int i = 0; i < n; i++) {
        // 题目要求：x ≡ b_i (mod a_i)
        // 这里的输入是 m[i] (模数), a[i] (余数)
        cin >> m[i] >> a[i];
    }
    cout << excrt() << endl;
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