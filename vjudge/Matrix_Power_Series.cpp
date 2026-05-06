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
const int N = 60;

int n, k, m;

struct mutrix {
    int m[N][N];
};

mutrix operator*(const mutrix &a, const mutrix &b) {
    mutrix c;
    memset(c.m, 0, sizeof c.m);
    for (int i = 0; i < n * 2; i++) { // ⚠️矩阵大小为n * 2
        for (int j = 0; j < n * 2; j++) {
            for (int k = 0; k < n * 2; k++) {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % m) % m;
            }
        }
    }
    return c;
}

mutrix qmi_mutrix(mutrix a, int p) {
    mutrix res;
    // 初始化为单位矩阵
    memset(res.m, 0, sizeof res.m);
    for (int i = 0; i < n * 2; i++) { // ⚠️矩阵大小为n * 2
        res.m[i][i] = 1;
    }
    while (p) {
        if (p & 1) // ⚠️p & 1, 取最低位
            res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k >> m;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    mutrix s;
    memset(s.m, 0, sizeof s.m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s.m[i][j] = a[i][j];
            s.m[i + n][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        s.m[i + n][i + n] = 1; // ⚠️初始化为单位矩阵，只需要初始化对角线
    }
    auto ans = qmi_mutrix(s, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans.m[i + n][j] << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
