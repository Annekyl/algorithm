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
constexpr int mod = 10000;
const int N = 1e5 + 10;

int n;

struct matrix {
    int m[2][2];
};

matrix operator*(const matrix &a, const matrix &b) {
    matrix c;
    memset(c.m, 0, sizeof c.m);
    auto &am = a.m;
    auto &bm = b.m;
    auto &cm = c.m;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cm[i][j] = (cm[i][j] + am[i][k] * bm[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

matrix pow_matrix(matrix a, int n) {
    matrix ans;
    memset(ans.m, 0, sizeof ans.m);
    for (int i = 0; i < 2; i++)
        ans.m[i][i] = 1;
    while (n) {
        if (n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

void solve() {
    matrix a;
    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;
    int ans = pow_matrix(a, n).m[0][1];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> n, n != -1) {
        solve();
    }

    return 0;
}
