// 旋转卡壳 (Rotating Calipers)
// AcWing 1402. 顶点对最大距离
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n;
struct Point {
    double x, y;
} p[N], stk[N];
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

// Andrew算法求凸包
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

// 旋转卡壳求凸包直径 (最远点对)
double rotating_calipers() {
    convex_hull();

    if (top <= 1) return 0;
    if (top == 2) return dist(stk[0], stk[1]);

    double res = 0;
    int k = 1;

    for (int i = 0; i < top - 1; i++) {
        while (cross(stk[i + 1] - stk[i], stk[k + 1] - stk[i]) >
               cross(stk[i + 1] - stk[i], stk[k] - stk[i]))
            k = (k + 1) % (top - 1);

        res = max(res, max(dist(stk[i], stk[k]), dist(stk[i + 1], stk[k + 1])));
    }

    return res;
}

// 旋转卡壳求最小矩形覆盖
double min_rectangle_area() {
    convex_hull();
    if (top <= 2) return 0;

    double res = 1e18;
    int k = 1, r = 1;

    for (int i = 0; i < top - 1; i++) {
        // 找最远点
        while (dist(stk[i], stk[k]) < dist(stk[i], stk[(k + 1) % (top - 1)]))
            k = (k + 1) % (top - 1);

        // 找最左边的点
        while (cross(stk[i + 1] - stk[i], stk[r + 1] - stk[i]) >
               cross(stk[i + 1] - stk[i], stk[r] - stk[i]))
            r = (r + 1) % (top - 1);

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
