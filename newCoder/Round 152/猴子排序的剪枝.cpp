#include "bits/stdc++.h"
#define int long long // 全程用 long long，防止取模乘法过程中溢出
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; // 题目要求的模数
const int N = 5010;            // n 的上限（本题实际未直接用到，习惯性预留）

// 快速幂：计算 a^b mod p
// 用途：本题里主要用来求乘法逆元（费马小定理：a^(p-2) ≡ a^(-1) (mod p)，p
// 为质数）
int qmi(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b & 1) // b 的最低位是 1，说明这一位对应的 a 的幂次要乘进结果
            res = res * a % p;
        a = a * a % p; // a 平方，对应二进制下一位的权值
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // 排序之后，相同值的元素会连续排列在一起，方便下面按值分组，
    // 而且分组的顺序天然就是"值从小到大"，正好符合后面 DP 转移时
    // "小值组必须整体排在大值组前面"这一要求。

    // ---------- 第一步：按值分组，为分组背包 DP 做准备 ----------
    // cnt[i] 表示第 i 组（按值从小到大排序后的第 i 组）里有多少个元素，
    // 即数组中原来相同的数值分别有几个（对应之前推导中的 c_i）。
    vi cnt;
    for (int i = 0; i < n;) {
        int j = i;
        // 从位置 i 开始往后扫，只要值和 a[i] 相同就继续扩展这一组
        while (j < n && a[j] == a[i])
            j++;
        cnt.push_back(j - i); // 这一组的大小 = j - i
        i = j;                // 跳到下一组的起始位置
    }
    int m = cnt.size(); // 一共有 m 个不同的取值（m 组）

    // ---------- 第二步：预处理阶乘与阶乘的逆元 ----------
    // fact[i]  = i!  (mod p)
    // inv[i]   = (i!)^(-1)  (mod p)，即 i! 的乘法逆元
    // 用途：
    //   1. 计算下降阶乘 (c)_k = c! / (c-k)! = fact[c] * inv[c-k]
    //   2. 计算最终公式里的 (n-j)!
    //   3. 计算最后除以 f(n) 时需要的逆元
    vi fact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    inv[n] = qmi(fact[n], mod - 2, mod); // 先求出 n! 的逆元（唯一一次用快速幂）
    // 倒推乘法逆元：inv[i-1] = inv[i] * i，
    // 因为 (i-1)! = i! / i，取逆元后就是 inv[i-1] = inv[i] * i (mod p)
    // 这样只用一次快速幂就能把所有阶乘的逆元都递推出来，效率更高
    for (int i = n; i > 0; i--)
        inv[i - 1] = inv[i] * i % mod;

    // ---------- 第三步：分组背包 DP，求 f(j) ----------
    // dp[j] 的含义（滚动数组，随着组的加入不断更新）：
    //   目前已经处理过的若干组元素中，选出 j 个、排成一个"值不下降"的
    //   有序序列，一共有多少种"选法+排法"的方案数。
    // 最终目标：dp[j] = f(j)，即前面推导中定义的 f(j)。
    vi dp(n + 1, 0);
    dp[0] = 1;   // 边界：一个元素都不选，只有空序列这一种方案，方案数为 1
    int len = 0; // len 表示"到目前为止已经并入 dp 的组"，其元素总数是多少
                 // （也就是当前 dp 数组里有意义的最大下标）

    // 依次把每一组"卷"进 dp 数组里（增量式分组背包）
    for (int i = 0; i < m; i++) {
        int c = cnt[i]; // 当前处理的这一组的大小 c_i

        // comb[k] = 从这一组的 c 个可区分元素中，选出 k 个并排成一列的方案数
        //         = 下降阶乘 (c)_k = c! / (c-k)!
        // 组内元素值相同，无论怎么排都满足"不下降"，所以组内顺序任意，
        // 这正是"选 k 个再排列"的方案数，而不是单纯的组合数 C(c,k)。
        vi comb(c + 1);
        for (int j = 0; j <= c; j++) {
            comb[j] = fact[c] * inv[c - j] % mod;
        }

        int newlen = len + c;  // 并入这一组之后，dp 数组能表示的最大选取个数
        vi ndp(newlen + 1, 0); // 新的 dp 数组（对应 dp[i][*]，i 为组的编号）

        // 转移方程：
        //   dp[i][j] = sum_{k=0}^{min(c,j)} dp[i-1][j-k] * (c_i)_k
        // 即：枚举这一组贡献了 k 个元素，其余 j-k 个元素由前面的组提供，
        // 因为这一组的值比之前所有组都大，所以这 k 个元素只能整体接在
        // 前面序列的末尾，两部分方案数按乘法原理相乘。
        for (int j = 0; j <= len; j++) {
            if (dp[j] == 0)
                continue;     // 剪枝：这个状态不可达，跳过
            int base = dp[j]; // 前面所有组贡献 j 个元素的方案数
            for (int k = 0; k <= c; k++) {
                // 把"前面部分方案数 base" 和 "这一组选 k 个的方案数 comb[k]"
                // 相乘，累加到新状态 ndp[j+k] 上（这是卷积的核心一步）
                ndp[j + k] = (ndp[j + k] + base * comb[k]) % mod;
            }
        }

        dp = move(ndp); // 滚动数组更新，移动语义避免额外拷贝开销
        len = newlen;   // 更新当前已处理的元素总数
    }
    // 循环结束后，len 应该恰好等于 n，dp[j] (j=0..n) 就是 f(j)：
    // 从全部 n 个元素中选出 j 个排成不下降序列的方案数。

    // ---------- 第四步：套用最终公式求答案 ----------
    // 推导结论：
    //   E[X]（单轮期望插入次数）   = sum_{j=0}^{n-1} f(j)*(n-j)! / n!
    //   p（单轮成功概率）          = f(n) / n!
    //   答案 = E[X] / p = ( sum_{j=0}^{n-1} f(j)*(n-j)! ) / f(n)
    // 注意 n! 在推导中被约掉了，所以这里不需要再乘/除 n!，
    // 只需要分子中每一项乘上 (n-j)! 即可。
    int s = 0;
    for (int i = 0; i < n; i++) {
        // s 累加 f(j) * (n-j)!，对应上面公式的分子部分（j 从 0 到 n-1）
        s = (s + dp[i] * fact[n - i]) % mod;
    }
    // 最后除以 f(n)（即 dp[n]），取模意义下的除法用乘逆元实现
    int ans = s * qmi(dp[n], mod - 2, mod) % mod;
    cout << ans << endl;
}

signed main() {
    // 因为开头 #define int long long，这里的 main 也要写成 signed main
    // （否则 int main() 会被宏替换成 long long main()，导致签名不匹配）
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;   // 如果有多组测试数据，取消这行注释
    while (t--) {
        solve();
    }

    return 0;
}