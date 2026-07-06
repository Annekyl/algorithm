// 凸包 (Convex Hull)
// AcWing 1401. 凸多边形 / 1400. 柱形纸牌
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

// Andrew算法求凸包
int convex_hull() {
    sort(p, p + n);

    // 下凸包
    for (int i = 0; i < n; i++) {
        while (top >= 2 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }

    // 上凸包
    int k = top;
    for (int i = n - 2; i >= 0; i--) {
        while (top >= k + 1 && cross(stk[top - 1] - stk[top - 2], p[i] - stk[top - 2]) <= 0)
            top--;
        stk[top++] = p[i];
    }

    return top - 1; // 凸包点数
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

// 计算凸包面积
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
