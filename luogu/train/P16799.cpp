#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

// 快速幂用于求逆元
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 模 MOD 意义下的乘法逆元
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int n, m;
vector<long long> a;
vector<long long> bit1; // 维护元素之和
vector<long long> bit2; // 维护元素平方之和

// 树状数组单点更新
void add1(int idx, long long val) {
    val = (val % MOD + MOD) % MOD;
    for (; idx <= n; idx += idx & -idx) {
        bit1[idx] = (bit1[idx] + val) % MOD;
    }
}

void add2(int idx, long long val) {
    val = (val % MOD + MOD) % MOD;
    for (; idx <= n; idx += idx & -idx) {
        bit2[idx] = (bit2[idx] + val) % MOD;
    }
}

// 树状数组前缀查询
long long query1(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum = (sum + bit1[idx]) % MOD;
    }
    return sum;
}

long long query2(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum = (sum + bit2[idx]) % MOD;
    }
    return sum;
}

int main() {
    // 优化标准 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    a.resize(n + 1);
    bit1.resize(n + 1, 0);
    bit2.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add1(i, a[i]);
        add2(i, a[i] * a[i] % MOD);
    }

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            
            long long len = r - l + 1;
            // 求区间和与区间平方和
            long long s = (query1(r) - query1(l - 1) + MOD) % MOD;
            long long s2 = (query2(r) - query2(l - 1) + MOD) % MOD;
            
            // 区间长度的逆元
            long long invLen = modInverse(len);
            
            // 平均值 = S / len
            long long avg = s * invLen % MOD;
            
            // 方差 = S2 - S^2 / len
            long long var = (s2 - s * s % MOD * invLen % MOD + MOD) % MOD;
            
            cout << avg << " " << var << "\n";
        } else if (type == 2) {
            int k;
            long long x;
            cin >> k >> x;
            
            // 计算变化量
            long long diff1 = (x - a[k]) % MOD;
            long long diff2 = (x * x % MOD - a[k] * a[k] % MOD) % MOD;
            
            // 更新树状数组
            add1(k, diff1);
            add2(k, diff2);
            
            // 更新原数组
            a[k] = x;
        }
    }

    return 0;
}