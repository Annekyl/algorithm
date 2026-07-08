// 最长上升子序列 (LIS - Longest Increasing Subsequence)
// AcWing 895. 最长上升子序列 / 896. 最长上升子序列 II
// 给定一个序列，找出最长的严格递增子序列的长度
// 三种解法：
//   1. O(n^2) DP：经典动态规划
//   2. O(n log n) 贪心 + 二分：维护一个辅助数组
//   3. O(n log n) + 记录方案：同时记录最优解的路径

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int dp[N]; // dp[i]: 以 a[i] 结尾的 LIS 长度

// ==================== O(n^2) DP ====================
// 转移：dp[i] = max(dp[j] + 1)，其中 j < i 且 a[j] < a[i]
// 时间复杂度：O(n^2)
int lis() {
    memset(dp, 0, sizeof dp);
    int res = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 1; // 最小为 1（只包含 a[i] 自身）
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

// ==================== O(n log n) 贪心 + 二分 ====================
// 核心：维护数组 q，q[i] 表示长度为 i+1 的 LIS 的最小结尾元素
// 性质：q 数组严格递增（因为更长的 LIS 结尾一定更大）
// 对于每个 a[i]，在 q 中二分查找第一个 >= a[i] 的位置，替换它
int lis_optimized() {
    int len = 0;        // 当前 LIS 长度
    int q[N];           // q[i]: 长度为 i+1 的 LIS 的最小结尾元素

    for (int i = 0; i < n; i++) {
        // 二分查找第一个 >= a[i] 的位置
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        q[l] = a[i];
        if (l == len) len++; // 扩展 LIS 长度
    }

    return len;
}

// ==================== O(n log n) + DP 记录方案 ====================
// 在 O(n log n) 的基础上，额外记录每个元素在 LIS 中的前驱
int pre[N]; // pre[i]: a[i] 在 LIS 中的前驱位置

int lis_with_path() {
    int len = 0;
    int q[N], pos[N]; // pos[i]: q[i] 在原数组中的位置

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        q[l] = a[i];
        pos[l] = i;              // 记录位置
        pre[i] = l > 0 ? pos[l - 1] : -1; // 记录前驱
        if (l == len) len++;
    }

    // 逆向输出 LIS
    int k = pos[len - 1];
    int res[N];
    for (int i = len - 1; i >= 0; i--) {
        res[i] = a[k];
        k = pre[k];
    }

    for (int i = 0; i < len; i++)
        printf("%d ", res[i]);
    printf("\n");

    return len;
}

// ==================== 最长不上升子序列 ====================
// 将 "严格递增" 改为 "非递增"（允许相等）
// 修改二分查找条件
int lis_non_increasing() {
    int len = 0;
    int q[N];

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= a[i]) l = mid + 1; // 注意：>=
            else r = mid;
        }
        q[l] = a[i];
        if (l == len) len++;
    }

    return len;
}

// ==================== 最长不下降子序列 ====================
// 将 "严格递增" 改为 "非递减"（允许相等）
int lis_non_decreasing() {
    int len = 0;
    int q[N];

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] <= a[i]) l = mid + 1; // 注意：<=
            else r = mid;
        }
        q[l] = a[i];
        if (l == len) len++;
    }

    return len;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("%d\n", lis_optimized());

    return 0;
}
