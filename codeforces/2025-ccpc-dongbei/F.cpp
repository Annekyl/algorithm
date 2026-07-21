#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

double get_hour(int x, int y) { return x * 30.0 + y * 0.5; }

double get_minute(int y) { return y * 6.0; }

double dist(double a, double b) {
    double mn = fabs(a - b);
    return min(mn, 360.0 - mn);
}

void solve() {
    int x0, x1, x2, y0, y1, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    double h0 = get_hour(x0, y0), m0 = get_minute(y0);
    int l = x1 * 60 + y1;
    int r = x2 * 60 + y2;
    double mn_cost = 1000;
    int time;
    for (int i = l; i <= r; i++) {
        int x = i / 60, y = i % 60;
        double h1 = get_hour(x, y), m1 = get_minute(y);
        double cost = dist(h0, h1) + dist(m0, m1);
        if (cost < mn_cost) {
            mn_cost = cost;
            time = i;
        }
    }
    cout << time / 60 << ' ' << time % 60 << endl;
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