// 欧拉函数 (Euler's Totient Function) + 线性筛
// AcWing 873. 欧拉函数 / 1292. 哥德巴赫猜想
// phi(n) 表示 [1, n] 中与 n 互质的数的个数
// 公式：若 n = p1^a1 * p2^a2 * ... * pk^ak
//      则 phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
// 时间复杂度：单次 O(sqrt(n))，线性筛 O(n)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];
int phi[N]; // phi[i]: i 的欧拉函数值

// 线性筛求欧拉函数
// 利用欧拉函数是积性函数的性质，在线性筛过程中递推
// 若 gcd(a, b) = 1，则 phi(a * b) = phi(a) * phi(b)
void get_euler(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1; // 质数 p 的欧拉函数 = p - 1
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                // primes[j] 整除 i：phi(primes[j] * i) = phi(i) * primes[j]
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            // primes[j] 不整除 i：gcd(primes[j], i) = 1
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

// 求单个数的欧拉函数
// 逐个分解质因子，利用公式 phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ...
// 注意：这里用 res / i * (i - 1) 代替 res * (i - 1) / i 避免溢出
int get_phi(int n) {
    int res = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i; // 除去所有因子 i
        }
    }
    if (n > 1) res = res / n * (n - 1); // 剩余一个大于 sqrt(n) 的质因子
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    get_euler(N - 1);

    while (n--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", phi[x]);
    }

    return 0;
}
