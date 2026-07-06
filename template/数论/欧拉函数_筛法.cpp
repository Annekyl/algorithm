// 欧拉函数 + 线性筛
// AcWing 873. 欧拉函数 / 1292. 哥德巴赫猜想
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];
int phi[N]; // 欧拉函数

// 线性筛求欧拉函数
void get_euler(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

// 求单个数的欧拉函数
int get_phi(int n) {
    int res = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * (n - 1);
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
