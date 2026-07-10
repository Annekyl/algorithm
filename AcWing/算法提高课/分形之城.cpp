#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

pii get_point(int n, int m) {
    if (n == 0)
        return {0, 0};

    int len = 1LL << (n - 1);
    int cnt = 1LL << (n * 2 - 2);

    int pos = m / cnt;
    int idx = m % cnt;

    auto [x, y] = get_point(n - 1, idx);

    if (pos == 0) {
        return {y, x};
    } else if (pos == 1) {
        return {x, y + len};
    } else if (pos == 2) {
        return {x + len, y + len};
    } else {
        return {2 * len - 1 - y, len - 1 - x};
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    auto [x1, y1] = get_point(n, a - 1);
    auto [x2, y2] = get_point(n, b - 1);

    double dx = x1 - x2;
    double dy = y1 - y2;
    int ans = round(sqrt(dx * dx + dy * dy) * 10);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
