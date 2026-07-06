// 莫比乌斯反演 + 线性筛
// AcWing 234. 放弃游戏 / 196. 质数距离
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000010;

int primes[N], cnt;
bool st[N];
int mu[N]; // 莫比乌斯函数
int d[N];  // 约数个数

void get_mobius(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                mu[primes[j] * i] = 0;
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
}

// 分块 + 前缀和优化
int pre[N], f[N];
int block_size;

void init() {
    block_size = sqrt(N);
    for (int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + mu[i];
}

int query(int n, int m) {
    int res = 0;
    for (int l = 1, r; l <= min(n, m); l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        res += (pre[r] - pre[l - 1]) * (n / l) * (m / l);
    }
    return res;
}

int main() {
    get_mobius(N - 1);
    init();

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", query(n, m));
    }

    return 0;
}
