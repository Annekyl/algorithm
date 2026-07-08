// 莫比乌斯反演 (Mobius Inversion) + 线性筛
// AcWing 234. 放弃游戏 / 196. 质数距离
// 莫比乌斯函数 mu(n)：
//   mu(1) = 1
//   若 n 有平方因子，mu(n) = 0
//   若 n = p1 * p2 * ... * pk (互不相同的质数)，mu(n) = (-1)^k
// 反演公式：若 f(n) = sum_{d|n} g(d)，则 g(n) = sum_{d|n} mu(n/d) * f(d)
// 应用：将求和条件从"整除"转化为"倍数"，简化计算

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000010;

int primes[N], cnt;
bool st[N];
int mu[N]; // mu[i]: 莫比乌斯函数值
int d[N];  // d[i]: i 的约数个数

// 线性筛莫比乌斯函数
// 利用 mu 是积性函数，在线性筛过程中递推
void get_mobius(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1; // 质数的 mu 值为 -1
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                mu[primes[j] * i] = 0; // 有平方因子，mu 为 0
                break;
            }
            mu[primes[j] * i] = -mu[i]; // 互质，mu 值取反
        }
    }
}

// 整除分块 + 前缀和优化
// 利用 mu 的前缀和，将 O(n) 的求和优化到 O(sqrt(n))
// 对于求和 sum_{i=1}^{n} f(i) * (n / i) * (m / i)
// 当 i 较大时，n/i 和 m/i 的值变化很慢，可以分块处理
int pre[N], f[N];
int block_size;

void init() {
    block_size = sqrt(N);
    // 预处理 mu 的前缀和
    for (int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + mu[i];
}

// 查询 sum_{i=1}^{min(n,m)} mu(i) * (n/i) * (m/i)
// 使用整除分块，O(sqrt(min(n,m))) 时间复杂度
int query(int n, int m) {
    int res = 0;
    for (int l = 1, r; l <= min(n, m); l = r + 1) {
        // 利用整除分块：对于 [l, r] 内的 i，n/i 和 m/i 的值相同
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
