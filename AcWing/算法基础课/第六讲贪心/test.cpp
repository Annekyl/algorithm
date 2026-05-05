#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int n; // 区间数量

// 定义区间结构体
struct Range {
    int l, r; // 区间的左右端点

    // 重载小于运算符，用于按左端点排序
    bool operator<(const Range &W) const {
        return l < W.l; // 按左端点从小到大排序
    }
} range[N]; // 存储所有区间

int main() {
    int st, ed;              // 目标区间的起点和终点
    scanf("%d%d", &st, &ed); // 读取目标区间
    scanf("%d", &n);         // 读取区间数量

    // 读取所有区间
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r}; // 存储区间
    }

    // 将所有区间按左端点从小到大排序
    // 这样我们可以按顺序处理，确保不会遗漏
    sort(range, range + n);

    int res = 0;          // 记录所需区间数量
    bool success = false; // 标记是否成功覆盖目标区间

    // 遍历所有区间
    for (int i = 0; i < n; i++) {
        int j = i;    // j用于扫描当前能覆盖st的区间
        int r = -2e9; // 记录当前能覆盖st的区间中的最大右端点

        // 扫描所有左端点小于等于当前st的区间
        // 找到其中右端点最大的区间
        while (j < n && range[j].l <= st) {
            r = max(r, range[j].r); // 更新最大右端点
            j++;
        }

        // 如果找到的最大右端点小于当前st，说明无法覆盖
        // 存在缺口，无法继续覆盖
        if (r < st) {
            res = -1; // 标记失败
            break;    // 退出循环
        }

        res++; // 选择当前找到的右端点最大的区间

        // 如果当前最大右端点已经覆盖完目标区间
        if (r >= ed) {
            success = true; // 标记成功
            break;          // 退出循环
        }

        st = r;    // 更新当前已经覆盖到的位置
        i = j - 1; // 跳过已经扫描过的区间，j指向第一个左端点大于原st的区间
    }

    // 如果循环结束但没有成功覆盖
    if (!success) {
        res = -1; // 输出-1表示失败
    }

    printf("%d\n", res); // 输出结果

    return 0;
}