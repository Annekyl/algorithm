#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long LL; // 使用长整型存储面积，避免溢出

// 函数：计算直方图中的最大矩形面积
LL largestRectangleArea(vector<LL> &heights) {
    stack<int> stk;         // 单调栈，存储的是矩形的索引
    LL max_area = 0;        // 初始化最大面积为0
    int n = heights.size(); // 矩形数量

    // 遍历所有矩形，包括一个虚拟的末尾矩形（高度为0）
    for (int i = 0; i <= n; ++i) {
        // 当前矩形的高度，如果是虚拟的末尾矩形则高度为0
        LL h = (i == n) ? 0 : heights[i];

        // 当栈不为空且当前高度小于栈顶矩形的高度时
        while (!stk.empty() && h < heights[stk.top()]) {
            // 弹出栈顶矩形，并获取其高度
            int height = heights[stk.top()];
            stk.pop();

            // 计算宽度：
            // 如果栈为空，宽度为当前索引i（因为可以延伸到最左边）
            // 否则，宽度为i - stk.top() - 1（即当前索引到栈顶索引的距离减1）
            int width = stk.empty() ? i : (i - stk.top() - 1);

            // 更新最大面积
            max_area = max(max_area, (LL)height * width);
        }

        // 将当前矩形的索引入栈
        stk.push(i);
    }

    return max_area;
}

int main() {
    ios::sync_with_stdio(false); // 禁用C和C++的输入输出同步，提高速度
    cin.tie(nullptr);            // 解除cin和cout的绑定，进一步提高速度

    int n;
    // 循环读取测试用例，直到n为0时结束
    while (cin >> n, n) {
        vector<LL> heights(n); // 存储每个矩形的高度
        for (int i = 0; i < n; ++i) {
            cin >> heights[i]; // 读取每个矩形的高度
        }
        // 计算并输出当前直方图的最大矩形面积
        cout << largestRectangleArea(heights) << '\n';
    }

    return 0;
}