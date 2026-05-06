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

    for (int i = 0; i < n; i++) { // 枚举每一列
        // 选择行
        int mx = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(a[mx][i]))
                mx = j;
        }
        if (fabs(a[mx][i]) < eps) {
            cout << "No Solution" << endl;
            return;
        }

        // 交换两行
        for (int j = 0; j <= n; j++)
            swap(a[i][j], a[mx][j]);

        // 系数转换为1
        double div = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= div;
        }

        // 消元
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            double mul = a[j][i] / a[i][i];
            for (int k = 0; k <= n; k++)
                a[j][k] -= a[i][k] * mul;
        }
    }

    for (int i = 0; i < n; i++) {
        // for (int j = 0; j <= n; j++) {
        // cout << a[i][n] << ' ';
        // }
        // cout << endl;
        printf("%.2lf\n", a[i][n]);
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
