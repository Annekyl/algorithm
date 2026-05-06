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

double eps = 1e-6;

void solve() {
    int n;
    cin >> n;
    double a[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int r = 0;
    for (int c = 0; c < n; c++) { // 枚举每一列
        // 选择行
        int mx = r;
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[mx][c]))
                mx = i;
        }
        if (fabs(a[mx][c]) < eps) {
            // 当前列没有主元
            continue;
        }

        // 交换两行
        for (int j = 0; j <= n; j++)
            swap(a[r][j], a[mx][j]);

        // 系数转换为1
        double div = a[r][c];
        for (int j = c; j <= n; j++) {
            a[r][j] /= div;
        }

        // 消元
        for (int i = 0; i < n; i++) {
            if (i == r)
                continue;
            double mul = a[i][c];
            for (int j = c; j <= n; j++)
                a[i][j] -= a[r][j] * mul;
        }

        // 处理下一行
        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    } else
        for (int i = 0; i < n; i++) {
            printf("x%d=%.2lf\n", i + 1, a[i][n]);
        }
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
