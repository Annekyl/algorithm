#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;

struct Node {
    int v, w;
    double p;
};

void solve() {
    cin >> n >> m;
    Node a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p >> a[i].v >> a[i].w;
        a[i].p /= 100.0;
    }
    sort(a + 1, a + n + 1, [](Node &x, Node &y) { return x.v < y.v; });

    vector<double> f(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i].w; j--) {
            f[j] = max(f[j], f[j - a[i].w] * (1 - a[i].p) + a[i].v * a[i].p);
        }
    }
    double ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(ans, f[i]);
    // cout << ans << endl;
    printf("%.12lf\n", ans);
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