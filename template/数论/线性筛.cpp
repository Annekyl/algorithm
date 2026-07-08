// 线性筛 (Linear Sieve / Euler Sieve)
// AcWing 868. 筛质数 / 1292. 哥德巴赫猜想
// 用 O(n) 时间筛出 [1, n] 内的所有质数，同时可筛出多种积性函数
// 核心思想：每个合数只被其最小质因子筛掉一次

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt; // primes: 质数表，cnt: 质数个数
bool st[N];         // st[i]: i 是否为合数

// 线性筛质数
// 关键：当 i % primes[j] == 0 时 break，确保 primes[j] 是 primes[j] * i 的最小质因子
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;  // i 是质数
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;   // 用 primes[j] 筛掉合数
            if (i % primes[j] == 0) break; // primes[j] 是 i 的最小质因子
        }
    }
}

// 线性筛最小质因子
// min_prime[i] 存储 i 的最小质因子，用于后续分解质因数
int min_prime[N];
void get_min_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            min_prime[i] = i;  // 质数的最小质因子是自己
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            min_prime[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

// 线性筛约数个数
// 设 n = p1^a1 * p2^a2 * ... * pk^ak，则 d(n) = (a1+1)(a2+1)...(ak+1)
// d_cnt[i] 记录最小质因子在 i 中的幂次
int d[N], d_cnt[N]; // d: 约数个数, d_cnt: 最小质因子的幂次
void get_divisor_count(int n) {
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            d[i] = 2;        // 质数有2个约数：1和它本身
            d_cnt[i] = 1;    // 最小质因子的幂次为1
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            min_prime[t] = primes[j];
            if (i % primes[j] == 0) {
                // primes[j] 整除 i，幂次加1
                d_cnt[t] = d_cnt[i] + 1;
                d[t] = d[i] / d_cnt[i] * (d_cnt[i] + 1);
                break;
            }
            // primes[j] 不整除 i，新引入一个质因子，幂次为1
            d[t] = d[i] * 2;
            d_cnt[t] = 1;
        }
    }
}

// 线性筛约数和
// 设 n = p1^a1 * p2^a2 * ... * pk^ak，则 s(n) = (1+p1+...+p1^a1)(1+p2+...+p2^a2)...(1+pk+...+pk^ak)
// s_cnt[i] 记录 i 中最小质因子对应的等比数列和
int s[N], s_cnt[N];
void get_divisor_sum(int n) {
    s[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            s[i] = i + 1;    // 质数的约数和 = 1 + p
            s_cnt[i] = i;    // 最小质因子对应的等比数列和
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            min_prime[t] = primes[j];
            if (i % primes[j] == 0) {
                // primes[j] 整除 i，等比数列多乘一项
                s_cnt[t] = s_cnt[i] * primes[j];
                s[t] = s[i] + s_cnt[t];
                break;
            }
            // primes[j] 不整除 i，新引入一个质因子
            s[t] = s[i] * (primes[j] + 1);
            s_cnt[t] = primes[j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    get_primes(n);

    printf("%d\n", cnt);

    return 0;
}
