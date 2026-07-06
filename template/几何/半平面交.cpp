// 半平面交 (Half Plane Intersection)
// AcWing 1414. 牛线
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
    Point p, v; // p为起点，v为方向向量
    double angle;
    bool operator<(const Line &l) const {
        return angle < l.angle;
    }
} line[N];

int n, cnt;

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
Point get_intersection(Line a, Line b) {
    Point u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}

// 判断点在直线左侧
bool on_left(Line l, Point p) {
    return cross(l.v, p - l.p) > eps;
}

// 半平面交
Point poly[N];
int half_plane_intersection() {
    sort(line, line + cnt);
    int que[N], hh = 0, tt = 0;
    que[0] = 0;

    for (int i = 1; i < cnt; i++) {
        if (fabs(line[i].angle - line[i - 1].angle) < eps) continue;
        while (hh < tt && !on_left(line[i], get_intersection(line[que[tt - 1]], line[que[tt]]))) tt--;
        while (hh < tt && !on_left(line[i], get_intersection(line[que[hh]], line[que[hh + 1]]))) hh++;
        que[++tt] = i;
    }

    while (hh < tt && !on_left(line[que[hh]], get_intersection(line[que[tt - 1]], line[que[tt]]))) tt--;

    int res = tt - hh + 1;
    for (int i = hh; i <= tt; i++)
        poly[i - hh] = get_intersection(line[que[i]], line[que[(i - hh + 1) % res + hh]]);

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        line[i] = {{x1, y1}, {x2 - x1, y2 - y1}};
        line[i].angle = atan2(line[i].v.y, line[i].v.x);
    }

    cnt = n;
    int res = half_plane_intersection();

    if (res <= 2) printf("0\n");
    else {
        double area = 0;
        for (int i = 0; i < res; i++)
            area += cross(poly[i], poly[(i + 1) % res]);
        printf("%.2f\n", fabs(area) / 2);
    }

    return 0;
}
