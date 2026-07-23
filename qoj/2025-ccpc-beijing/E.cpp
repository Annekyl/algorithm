#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<double, double> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

double get_dist(double x0, double y0, double x1, double y1) {
    double dx = abs(x0 - x1), dy = abs(y0 - y1);
    double dist = sqrt(dx * dx + dy * dy);
    return dist;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> point(n);
    for (int i = 0; i < n; i++)
        cin >> point[i].first >> point[i].second;
    int a, b, c;
    cin >> a >> b >> c;

    double len = sqrt(1.0 * a * a + 1.0 * b * b);
    double ux = b / len; // 单位方向向量
    double uy = -a / len;
    double x0 = 0, y0 = 0; // 基准点
    if (a != 0) {
        x0 = (double)(-c) / a;
        y0 = 0;
    } else {
        x0 = 0;
        y0 = (double)(-c) / b;
    }

    auto check = [&](double mid) -> bool {
        double l = -INF, r = INF;
        for (auto [x, y] : point) {
            double d = abs(a * x + b * y + c) / len;
            if (d > mid)
                return false;

            // 投影点
            double dx = x - x0, dy = y - y0;
            double t = dx * ux + dy * uy;

            double hu = sqrt(mid * mid - d * d);
            l = max(l, t - hu);
            r = min(r, t + hu);
            if (l > r)
                return false;
        }
        return true;
    };

    double l = 0, r = INF;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    double ans = r;
    printf("%.8lf\n", ans);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}