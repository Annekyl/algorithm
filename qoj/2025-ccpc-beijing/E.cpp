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
    double dx=abs(x0-x1),dy=abs(y0-y1);
    double dist=sqrt(dx*dx+dy*dy);
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
    sort(point.begin(), point.end());
    double l = point[0].first, r = point[n - 1].first;

    auto check = [&](double x0) -> bool {
        double y0 = (-a * x0 - c) / b;
        double mx=0;
        for(auto [x1,y1]:point){
            double dist=get_dist(x0,y0,x1,y1);
            mx=max(mx,dist);
        }
        return 
    };

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}