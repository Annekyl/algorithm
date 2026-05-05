#include <algorithm>
#include <iostream>

using namespace std;

// 定义类型别名
typedef long long LL;      // 使用long long防止大数计算溢出
typedef pair<LL, int> PII; // 存储数值和原始索引的pair
const int N = 100010;      // 数组最大容量

// 全局变量
int n;          // 序列长度
int l[N], r[N]; // 双向链表，l[i]表示i的左邻居，r[i]表示i的右邻居
int p[N];       // p[i]表示原始序列中第i个元素在排序后的位置
PII a[N];       // 存储序列数据，first为数值，second为原始索引
PII ans[N];     // 存储答案，first为最小差值，second为对应的j

int main() {
    // 输入处理
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first; // 读取数值
        a[i].second = i;   // 记录原始索引
    }

    // 对序列进行排序（按数值大小）
    sort(a + 1, a + 1 + n);

    // 初始化双向链表和边界
    a[0].first = -3e9;    // 设置左边界为极小值
    a[n + 1].first = 3e9; // 设置右边界为极大值
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;       // 初始化左邻居
        r[i] = i + 1;       // 初始化右邻居
        p[a[i].second] = i; // 记录原始索引到排序位置的映射
    }

    // 从后往前处理每个元素
    for (int i = n; i > 1; i--) {
        int j = p[i];     // 获取当前元素在排序后的位置
        int left = l[j];  // 左邻居位置
        int right = r[j]; // 右邻居位置

        // 计算与左右邻居的差值
        LL left_value = abs(a[left].first - a[j].first);
        LL right_value = abs(a[right].first - a[j].first);

        // 选择差值较小的邻居，若相同则选择值较小的（由于从左往右处理，自动满足）
        if (left_value <= right_value)
            ans[i] = {left_value, a[left].second};
        else
            ans[i] = {right_value, a[right].second};

        // 从链表中移除当前元素（更新邻居关系）
        l[right] = left;
        r[left] = right;
    }

    // 输出结果（从第二个元素开始）
    for (int i = 2; i <= n; i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}