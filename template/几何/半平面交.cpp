// 半平面交 (Half Plane Intersection)
// AcWing 1414. 牛线
// 给定若干条有向直线（半平面），求它们的交集
// 半平面：直线左侧（或右侧）的所有点
// 时间复杂度：O(n log n)
// 核心思想：
//   1. 按直线角度排序
//   2. 用双端队列维护当前交集的边界
//   3. 依次加入每条直线，维护交集
// 应用：
//   - 求凸多边形的交
//   - 线性规划

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1010;
const double eps = 1e-9;

struct Point {
    double x, y;
};

struct Line {
    Point p, v; // p: 起点, v: 方向向量
    double angle; // 方向向量的角度（用于排序）
    bool operator<(const Line &l) const {
        return angle < l.angle;
    }
} line[N];

int n, cnt; // cnt: 有效直线数

Point operator+(Point a, Point b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator*(Point a, double t) {
    return {a.x * t, a.y * t};
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// 求两直线交点
// 设直线 a: p + t * v，直线 b: q + s * w
// 交点满足：cross(v, q - p) / cross(v, w)
Point get_intersection(Line a, Line b) {
    Point u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}

// 判断点 p 在直线 l 的左侧
// cross(l.v, p - l.p) > 0 表示在左侧
bool on_left(Line l, Point p) {
    return cross(l.v, p - l.p) > eps;
}

// 半平面交
// 1. 按角度排序
// 2. 用双端队列维护边界
// 3. 依次加入直线，维护交集
Point poly[N]; // 存储交集的顶点
int half_plane_intersection() {
    sort(line, line + cnt); // 按角度排序
    int que[N], hh = 0, tt = 0;
    que[0] = 0;

    for (int i = 1; i < cnt; i++) {
        if (fabs(line[i].angle - line[i - 1].angle) < eps) continue; // 平行线跳过
        // 移除队尾不合法的直线
        while (hh < tt && !on_left(line[i], get_intersection(line[que[tt - 1]], line[que[tt]]))) tt--;
        // 移除队首不合法的直线
        while (hh < tt && !on_left(line[i], get_intersection(line[que[hh]], line[que[hh + 1]]))) hh++;
        que[++tt] = i;
    }

    // 处理首尾
    while (hh < tt && !on_left(line[que[hh]], get_intersection(line[que[tt - 1]], line[que[tt]]))) tt--;

    int res = tt - hh + 1;
    // 计算交集顶点
    for (int i = hh; i <= tt; i++)
        poly[i - hh] = get_intersection(line[que[i]], line[que[(i - hh + 1) % res + hh]]);

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        line[i] = {{x1, y1}, {x2 - x1, y2 - y1}}; // 方向向量
        line[i].angle = atan2(line[i].v.y, line[i].v.x); // 计算角度
    }

    cnt = n;
    int res = half_plane_intersection();

    if (res <= 2) printf("0\n"); // 交集面积为 0
    else {
        // 计算交集面积（叉积法）
        double area = 0;
        for (int i = 0; i < res; i++)
            area += cross(poly[i], poly[(i + 1) % res]);
        printf("%.2f\n", fabs(area) / 2);
    }

    return 0;
}
