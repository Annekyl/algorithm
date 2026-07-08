// 凸包 (Convex Hull)
// AcWing 1401. 凸多边形 / 1400. 柱形纸牌
// 凸包：包含所有点的最小凸多边形
// Andrew 算法：
//   1. 按 x 坐标排序（x 相同按 y 排序）
//   2. 分别构建下凸包和上凸包
//   3. 利用叉积判断方向，维护凸包
// 时间复杂度：O(n log n)
// 空间复杂度：O(n)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n;
struct Point {
    double x, y;
} p[N], stk[N]; // stk: 凸包栈
int top;

// 点的比较（先按 x，再按 y）
bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// 向量减法
Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

// 叉积：a × b = |a||b|sin(θ)
// 正值表示 b 在 a 的逆时针方向
// 负值表示 b 在 a 的顺时针方向
// 0 表示 a 和 b 共线
double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

// Andrew 算法求凸包
// 1. 按 x 坐标排序
// 2. 构建下凸包：从左到右扫描，维护凸性
// 3. 构建上凸包：从右到左扫描，维护凸性
int convex_hull() {
    sort(p, p + n);

    // 构建下凸包
    for (int i = 0; i < n; i++) {
        // 叉积 <= 0 表示不满足凸性，弹出栈顶
        while (top >= 2 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }

    // 构建上凸包
    int k = top; // 记录下凸包的大小
    for (int i = n - 2; i >= 0; i--) {
        while (top >= k + 1 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }

    return top - 1; // 凸包点数（减去重复的起点）
}

// 计算凸包周长
double perimeter() {
    int m = convex_hull();
    double res = 0;
    for (int i = 0; i < m; i++) {
        double dx = stk[i].x - stk[(i + 1) % m].x;
        double dy = stk[i].y - stk[(i + 1) % m].y;
        res += sqrt(dx * dx + dy * dy);
    }
    return res;
}

// 计算凸包面积（叉积法）
// 面积 = 0.5 * |sum(cross(p[i], p[i+1]))|
double area() {
    int m = convex_hull();
    double res = 0;
    for (int i = 0; i < m; i++) {
        res += cross(stk[i], stk[(i + 1) % m]);
    }
    return fabs(res) / 2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);

    int m = convex_hull();
    printf("%d\n", m);

    for (int i = 0; i < m; i++)
        printf("%.0f %.0f\n", stk[i].x, stk[i].y);

    return 0;
}
