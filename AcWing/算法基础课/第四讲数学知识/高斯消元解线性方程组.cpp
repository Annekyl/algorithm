#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int guess() {
    int r, c;
    for (r = 1, c = 1; c <= n; c++) {
        // 找到绝对值最大的行
        int t = r;
        for (int i = r; i <= n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }
        // 当前行的第一个值为零
        if (fabs(a[t][c]) < eps)
            continue;

        // 先将当前行换到最上面
        FOR(i, c, n + 1) swap(a[t][i], a[r][i]);

        // 将当前行第一个元素标准化为1
        REF(i, n + 1, c) a[r][i] /= a[r][c];
        // 消去下面行的第一个元素
        FOR(i, r + 1, n) {
            if (fabs(a[i][c]) > eps) {
                REF(j, n + 1, c) { a[i][j] -= a[r][j] * a[i][c]; }
            }
        }
        r++;
    }
    if (r <= n) {
        FOR(i, r, n) {
            // 无解
            if (fabs(a[i][n + 1]) > eps)
                return 0;
        }
        // 无穷解
        return 2;
    }

    REF(i, n, 1) {
        FOR(j, i + 1, n) { a[i][n + 1] -= a[i][j] * a[j][n + 1]; }
    }
    return 1; // 有唯一解
}

void solve() {
    cin >> n;
    FOR(i, 1, n) {
        FOR(j, 1, n + 1) { cin >> a[i][j]; }
    }

    int t = guess();

    if (t == 1) {
        // FOR(i, 1, n) cout << a[i][n + 1] << endl;
        FOR(i, 1, n) printf("%.2f\n", a[i][n + 1]);
    } else if (t == 2) {
        cout << "Infinite group solutions" << endl;
    } else {
        cout << "No solution" << endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}