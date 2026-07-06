// 线性筛
// AcWing 868. 筛质数 / 1292. 哥德巴赫猜想
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

// 线性筛质数
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

// 线性筛最小质因子
int min_prime[N];
void get_min_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            min_prime[i] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            min_prime[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

// 线性筛约数个数
int d[N], d_cnt[N]; // d: 约数个数, d_cnt: 最小质因子的幂次
void get_divisor_count(int n) {
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            d[i] = 2;
            d_cnt[i] = 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            min_prime[t] = primes[j];
            if (i % primes[j] == 0) {
                d_cnt[t] = d_cnt[i] + 1;
                d[t] = d[i] / d_cnt[i] * (d_cnt[i] + 1);
                break;
            }
            d[t] = d[i] * 2;
            d_cnt[t] = 1;
        }
    }
}

// 线性筛约数和
int s[N], s_cnt[N];
void get_divisor_sum(int n) {
    s[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!min_prime[i]) {
            primes[cnt++] = i;
            s[i] = i + 1;
            s_cnt[i] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            min_prime[t] = primes[j];
            if (i % primes[j] == 0) {
                s_cnt[t] = s_cnt[i] * primes[j];
                s[t] = s[i] + s_cnt[t];
                break;
            }
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
