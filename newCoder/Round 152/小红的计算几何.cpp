#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<double, double> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

double get_distance(pii a, pii b) {
    double dx = abs(a.first - b.first);
    double dy = abs(a.second - b.second);
    return sqrt(dx * dx + dy * dy);
}

void solve() {
    int k;
    cin >> k;
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double ans = k * k + (abs(c - a) + abs(d - b)) * k;
    // cout << ans << endl;
	printf("%.8lf",ans);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
