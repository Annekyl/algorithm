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

int n;
int a[N][N];

int gauss() {
    int row, column;
    for (row = 1, column = 1; column <= n; column++) {
        // 找到非零行
        int t = row;
        FOR(i, row, n) {
            if (a[i][column]) {
                t = i;
                break;
            }
        }
        if (a[t][column] == 0) {
            continue;
        }

        // 将改行换到上面
        if (t != row) {
            FOR(i, column, n + 1) swap(a[t][i], a[row][i]);
        }
        // 消去其他行的非零元
        FOR(i, row + 1, n) {
            if (a[i][column] == 1) {
                FOR(j, column, n + 1) a[i][j] ^= a[row][j];
            }
        }

        row++;
    }
    if (row <= n) {
        FOR(i, row, n) {
            if (a[i][n + 1] != 0) {
                // 无解
                return 1;
            }
        }
        // 有无穷多解
        return 2;
    }

    // 唯一解
    // 回代操作
    REF(i, n - 1, 1) {
        FOR(j, i + 1, n) {
            if (a[i][j] == 1) {
                a[i][n + 1] ^= a[j][n + 1];
            }
        }
    }

    return 0;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) {
        FOR(j, 1, n + 1) { cin >> a[i][j]; }
    }

    int t = gauss();
    if (t == 0) {
        FOR(i, 1, n) cout << a[i][n + 1] << endl;
    } else if (t == 1) {
        cout << "No solution" << endl;
    } else {
        cout << "Multiple sets of solutions";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}