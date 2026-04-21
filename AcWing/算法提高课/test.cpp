// 实验1：统计求最大、最小元素的平均比较次数
// 使用锦标赛（Tournament）算法，比较次数约为 3n/2 - 2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cmpCount;

// 锦标赛算法：两两配对，大者比max，小者比min
void findMaxMin(int arr[], int n, int &maxVal, int &minVal) {
    cmpCount = 0;
    int i;
    if (n % 2 == 1) {
        maxVal = minVal = arr[0];
        i = 1;
    } else {
        cmpCount++;
        if (arr[0] >= arr[1]) { maxVal = arr[0]; minVal = arr[1]; }
        else                  { maxVal = arr[1]; minVal = arr[0]; }
        i = 2;
    }
    while (i + 1 < n) {
        int big, small;
        cmpCount++;
        if (arr[i] >= arr[i+1]) { big = arr[i]; small = arr[i+1]; }
        else                    { big = arr[i+1]; small = arr[i]; }
        cmpCount++;
        if (big > maxVal) maxVal = big;
        cmpCount++;
        if (small < minVal) minVal = small;
        i += 2;
    }
    // n为奇数时处理最后一个元素
    if (i < n) {
        cmpCount++;
        if (arr[i] > maxVal) maxVal = arr[i];
        cmpCount++;
        if (arr[i] < minVal) minVal = arr[i];
    }
}

int main() {
    srand((unsigned)time(0));
    int totalCmp = 0;
    const int RUNS = 10;
    const int N = 10;

    for (int t = 0; t < RUNS; t++) {
        int arr[N];
        cout << "第" << t+1 << "次 数组：";
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 20 + 1;
            cout << arr[i] << " ";
        }
        int maxVal, minVal;
        findMaxMin(arr, N, maxVal, minVal);
        cout << "  Max=" << maxVal << "  Min=" << minVal
             << "  比较次数=" << cmpCount << endl;
        totalCmp += cmpCount;
    }
    cout << "\n平均比较次数：" << totalCmp * 1.0 / RUNS << endl;
    // 理论值：3*10/2 - 2 = 13
    cout << "理论最优值（3n/2-2）= " << 3*N/2 - 2 << endl;
    return 0;
}