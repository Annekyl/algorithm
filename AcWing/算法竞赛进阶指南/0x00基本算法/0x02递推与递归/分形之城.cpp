#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;
ll a, b;

pll calc(int n, ll idx) {
    if (n == 1) {
        if (idx == 0)
            return {0, 0};
        if (idx == 1)
            return {0, 1};
        if (idx == 2)
            return {1, 1};
        if (idx == 3)
            return {1, 0};
    }
    ll len = 1ll << (n - 1);     // 分块的边长
    ll cnt = 1ll << (2 * n - 2); // 分块包含的街区数量
    pll pos = calc(n - 1, idx % cnt);
    ll x = pos.first, y = pos.second;
    ll z = idx / cnt; // 位于哪一块分区
    if (z == 0) {     // 左上
        return {y, x};
    } else if (z == 1) { // 右上
        return {x, y + len};
    } else if (z == 2) { // 右下
        return {x + len, y + len};
    } else { // 左下
        return {len * 2 - 1 - y, len - 1 - x};
    }
}

void solve() {
    cin >> n >> a >> b;
    pll p1 = calc(n, a - 1);
    pll p2 = calc(n, b - 1);
    double dx = p1.first - p2.first, dy = p1.second - p2.second;
    double ans = sqrt((dx * dx + dy * dy) * 10);
    // cout << setprecision(0) << ans << endl;
    // 使用printf打印double类型，控制输出小数点位数，实现四舍五入
    printf("%.0lf\n", sqrt((dx * dx + dy * dy)) * 10);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}