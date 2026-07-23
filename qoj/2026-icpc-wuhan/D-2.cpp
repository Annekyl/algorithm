#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化输入输出流速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long n;
    if (!(cin >> n)) return 0;

    // 边界情况处理
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // 1. 预处理 10^18 范围内的所有 3-smooth 数 (只包含质因子 2 和 3)
    vector<unsigned long long> smooth3;
    unsigned long long limit = 2e18; // 安全上界
    unsigned long long p3 = 1;
    
    for (int i = 0; i <= 40; ++i) { // 3^38 > 10^18
        unsigned long long p2 = 1;
        for (int j = 0; j <= 62; ++j) { // 2^60 > 10^18
            smooth3.push_back(p2 * p3);
            if (p2 > limit / 2) break;
            p2 *= 2;
        }
        if (p3 > limit / 3) break;
        p3 *= 3;
    }
    // 排序以便二分查找
    sort(smooth3.begin(), smooth3.end());

    // 2. 递推计算 A_k 数组 (A[k-1] 存储达到 k 个回合所需的最小数字 n)
    vector<unsigned long long> A;
    A.push_back(2); // A_1 = 2

    while (A.back() <= (unsigned long long)1e18) {
        unsigned long long curA = A.back();

        // 策略 1: P(g) = 2 的情况
        // Y 是大于等于 curA 的最小的 2 的幂
        unsigned long long Y = 1;
        while (Y < curA) Y *= 2;

        // 策略 2: P(g) = 3 的情况
        // 找到满足 3 * y3 >= curA 的最小 3-smooth 数 y3
        unsigned long long target = (curA + 2) / 3; // 向上取整
        auto it = lower_bound(smooth3.begin(), smooth3.end(), target);
        unsigned long long y3 = *it;
        unsigned long long v3_half = (y3 * 9) / 2;

        // 综合两种策略取最小
        unsigned long long nextA = min(Y, v3_half) + 1;
        A.push_back(nextA);
    }

    // 3. 回答查询
    // A 数组中严格大于 n 的第一个元素的索引即为最大回合数
    int ans = upper_bound(A.begin(), A.end(), n) - A.begin();
    
    cout << ans << "\n";

    return 0;
}