// 旋转卡壳 (Rotating Calipers)
// AcWing 1402. 顶点对最大距离
// 在凸包上寻找最远点对（凸包直径）
// 时间复杂度：O(n)，先求凸包 O(n log n)，再旋转卡壳 O(n)
// 核心思想：
//   1. 凸包的最远点对一定在凸包上
//   2. 对于凸包上的每条边，维护距离最远的点
//   3. 当边旋转时，最远点也单调移动（卡壳）
// 应用：
//   - 凸包直径（最远点对距离）
//   - 最小矩形覆盖
//   - 最远点对

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n;
struct Point {
    double x, y;
} p[N], stk[N]; // stk: 凸包
int top;

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Andrew 算法求凸包（不包含重复的起点）
void convex_hull() {
    sort(p, p + n);

    for (int i = 0; i < n; i++) {
        while (top >= 2 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }

    int k = top;
    for (int i = n - 2; i >= 0; i--) {
        while (top >= k + 1 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }
}

// 旋转卡壳求凸包直径（最远点对）
// 核心：对于每条边 (stk[i], stk[i+1])，找到距离最远的点 stk[k]
// 当边旋转时，k 也单调旋转
double rotating_calipers() {
    convex_hull();

    if (top <= 1) return 0;
    if (top == 2) return dist(stk[0], stk[1]);

    double res = 0;
    int k = 1; // 当前最远点

    for (int i = 0; i < top - 1; i++) {
        // 叉积：判断 stk[k+1] 是否比 stk[k] 更远
        while (cross(stk[i + 1] - stk[i], stk[k + 1] - stk[i]) >
               cross(stk[i + 1] - stk[i], stk[k] - stk[i]))
            k = (k + 1) % (top - 1);

        // 更新最远距离
        res = max(res, max(dist(stk[i], stk[k]), dist(stk[i + 1], stk[k + 1])));
    }

    return res;
}

// 旋转卡壳求最小矩形覆盖
// 对于凸包的每条边，维护三个卡壳点：
//   k: 最远点（确定矩形的一边）
//   r: 最左边的点（确定矩形的另一边）
// 面积 = 底 * 高
double min_rectangle_area() {
    convex_hull();
    if (top <= 2) return 0;

    double res = 1e18;
    int k = 1, r = 1;

    for (int i = 0; i < top - 1; i++) {
        // 找最远点（确定矩形的高）
        while (dist(stk[i], stk[k]) < dist(stk[i], stk[(k + 1) % (top - 1)]))
            k = (k + 1) % (top - 1);

        // 找最左边的点（确定矩形的底）
        while (cross(stk[i + 1] - stk[i], stk[r + 1] - stk[i]) >
               cross(stk[i + 1] - stk[i], stk[r] - stk[i]))
            r = (r + 1) % (top - 1);

        // 计算矩形面积
        double w = fabs(cross(stk[i + 1] - stk[i], stk[k] - stk[i])) /
                   fabs(stk[i + 1] - stk[i]);
        double h = fabs(cross(stk[i + 1] - stk[i], stk[r] - stk[i])) /
                   fabs(stk[i + 1] - stk[i]);

        res = min(res, w * h);
    }

    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);

    printf("%.0f\n", rotating_calipers());

    return 0;
}
