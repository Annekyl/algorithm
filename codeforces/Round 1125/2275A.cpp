#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int x0, y0, r;
    cin >> x0 >> y0 >> r;
    // int dx, dy;
    // for (int i = 0; i < r; i++) {
    //     int a = i;
    //     int b2 = r * r - a * a;
    //     int b = sqrt(b2);
    //     if (b * b == b2) {
    //         dx = a, dy = b;
    //         break;
    //     }
    // }
    cout << x0 << ' ' << y0 + r << endl;
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
