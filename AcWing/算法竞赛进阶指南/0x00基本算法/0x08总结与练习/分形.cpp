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
constexpr int N = 1000;

int pow3[10];

vector<vector<char>> a(N, vector<char>(N));

void b(int n, int stx, int sty) {
    if (n == 1) {
        a[stx][sty] = 'X';
        return;
    }
    int sz = pow3[n - 2];

    b(n - 1, stx, sty);
    b(n - 1, stx, sty + 2 * sz);
    b(n - 1, stx + sz, sty + sz);
    b(n - 1, stx + 2 * sz, sty);
    b(n - 1, stx + 2 * sz, sty + 2 * sz);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 预处理3的倍数
    FOR(i, 0, 9) pow3[i] = pow(3, i);

    int n;
    while (cin >> n, n != -1) {
        FOR(i, 0, N - 1) fill(a[i].begin(), a[i].end(), ' ');
        b(n, 1, 1);

        int sz = pow3[n - 1];
        FOR(i, 1, sz) {
            FOR(j, 1, sz) { cout << a[i][j]; }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}