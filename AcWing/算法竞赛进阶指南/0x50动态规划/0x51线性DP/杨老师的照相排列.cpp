#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;
int a[10];

void solve() {
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll f[a[1] + 1][a[2] + 1][a[3] + 1][a[4] + 1][a[5] + 1];
    memset(f, 0, sizeof(f));
    f[0][0][0][0][0] = 1;
    for (int i = 0; i <= a[1]; i++) {
        for (int j = 0; j <= a[2]; j++) {
            for (int k = 0; k <= a[3]; k++) {
                for (int l = 0; l <= a[4]; l++) {
                    for (int m = 0; m <= a[5]; m++) {
                        if (i < a[1])
                            f[i + 1][j][k][l][m] += f[i][j][k][l][m];
                        if (j < a[2] && i > j)
                            f[i][j + 1][k][l][m] += f[i][j][k][l][m];
                        if (k < a[3] && j > k)
                            f[i][j][k + 1][l][m] += f[i][j][k][l][m];
                        if (l < a[4] && k > l)
                            f[i][j][k][l + 1][m] += f[i][j][k][l][m];
                        if (m < a[5] && l > m)
                            f[i][j][k][l][m + 1] += f[i][j][k][l][m];
                    }
                }
            }
        }
    }
    cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}