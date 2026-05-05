#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL; // 定义一个坐标点类型，存储两个长整型数值

// 函数 calc 递归计算希尔伯特曲线中编号为 m 的点的坐标
// 参数 n: 希尔伯特曲线的阶数
// 参数 m: 点的编号（0-based）
PLL calc(LL n, LL m) {
    if (!n) // 递归基：0阶希尔伯特曲线只有一个点 (0, 0)
        return {0, 0};

    LL len = 1ll << (n - 1); // 当前阶数的子块边长（1左移n-1位，相当于2^(n-1)）
    LL cnt = 1ll << (2 * n - 2); // 当前阶数的子块包含的点数（2^(2n-2)）

    auto pos = calc(n - 1, m % cnt); // 递归计算低一阶的坐标
    auto x = pos.first, y = pos.second;
    auto z = m / cnt; // 确定当前点位于哪个象限（0~3）

    // 根据象限位置调整坐标
    if (z == 0) // 第一象限：顺时针旋转90度并翻转
        return {y, x};
    if (z == 1) // 第二象限：直接平移y坐标
        return {x, y + len};
    if (z == 2) // 第三象限：直接平移x和y坐标
        return {x + len, y + len};
    // 第四象限：逆时针旋转90度并翻转，然后平移
    return {len * 2 - 1 - y, len - x - 1};
}

int main() {
    int T;
    cin >> T; // 输入测试用例数量
    while (T--) {
        LL N, A, B;
        cin >> N >> A >> B;       // 输入阶数N和两个点的编号A、B
        auto ac = calc(N, A - 1); // 计算A的坐标（转换为0-based）
        auto bc = calc(N, B - 1); // 计算B的坐标（转换为0-based）
        double x = ac.first - bc.first, y = ac.second - bc.second; // 计算坐标差
        printf("%.0lf\n",
               sqrt(x * x + y * y) * 10); // 输出欧几里得距离（四舍五入取整）
    }
    return 0;
}