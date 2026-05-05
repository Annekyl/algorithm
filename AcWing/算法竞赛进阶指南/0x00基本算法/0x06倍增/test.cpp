#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const int MAXN = 500010;

int K, N, M;
LL T;
int A[MAXN];
int B[MAXN];      // 临时数组用于排序
int merged[MAXN]; // 归并排序的临时数组

// 计算区间[l, r]的校验值
LL calculate(int l, int r) {
    int m = 0;
    for (int i = l; i <= r; i++) {
        B[m++] = A[i];
    }
    sort(B, B + m);

    LL sum = 0;
    int left = 0, right = m - 1;
    for (int i = 0; i < M && left < right; i++) {
        LL diff = B[right] - B[left];
        sum += diff * diff;
        left++;
        right--;
    }
    return sum;
}

// 使用倍增算法求解最少分段数
int solve() {
    int ans = 0;
    int start = 0; // 当前段的起始位置
    while (start < N) {
        ans++; // 增加一段

        int len = 1;     // 初始步长
        int end = start; // 当前段的结束位置

        while (len > 0) {
            if (end + len <= N) { // 确保不越界
                LL val = calculate(start, end + len - 1);
                if (val <= T) {
                    end += len; // 扩展成功，移动结束位置
                    len *= 2;   // 尝试更大的步长
                } else {
                    len /= 2; // 步长过大，减半
                }
            } else {
                len /= 2; // 越界，减半步长
            }
        }

        start = end; // 下一段的起始位置
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    while (K--) {
        cin >> N >> M >> T;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << solve() << '\n';
    }

    return 0;
}