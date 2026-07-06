// 最长上升子序列 (LIS)
// AcWing 895. 最长上升子序列 / 896. 最长上升子序列 II
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int dp[N]; // dp[i]: 以a[i]结尾的LIS长度

// O(n^2) DP
int lis() {
    memset(dp, 0, sizeof dp);
    int res = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

// O(nlogn) 贪心 + 二分
int lis_optimized() {
    int len = 0;
    int q[N]; // q[i]: 长度为i+1的LIS的最小结尾元素

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        q[l] = a[i];
        if (l == len) len++;
    }

    return len;
}

// O(nlogn) + DP记录方案
int pre[N]; // pre[i]: a[i]在LIS中的前驱

int lis_with_path() {
    int len = 0;
    int q[N], pos[N]; // pos[i]: q[i]在原数组中的位置

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        q[l] = a[i];
        pos[l] = i;
        pre[i] = l > 0 ? pos[l - 1] : -1;
        if (l == len) len++;
    }

    // 输出LIS
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

// 最长不上升子序列
int lis_non_increasing() {
    int len = 0;
    int q[N];

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= a[i]) l = mid + 1; // 注意这里
            else r = mid;
        }
        q[l] = a[i];
        if (l == len) len++;
    }

    return len;
}

// 最长不下降子序列
int lis_non_decreasing() {
    int len = 0;
    int q[N];

    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] <= a[i]) l = mid + 1; // 注意这里
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
