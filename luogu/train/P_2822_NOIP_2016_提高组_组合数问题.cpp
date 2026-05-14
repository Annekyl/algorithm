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
const int N = 2010;

int k;
int c[N][N];
int s[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    // int ans = 0;
    cout << s[n][m] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t >> k;
    c[0][0] = 1;
    c[1][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = 1 % k;
        c[i][i] = 1 % k;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool suc = false;
            if (j <= i && c[i][j] == 0) {
                suc = true;
            }
            if (i > 0 && j > 0)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + suc;
            else if (i > 0)
                s[i][j] = s[i - 1][j] + suc;
            else if (j > 0)
                s[i][j] = s[i][j - 1] + suc;
            else
                s[i][j] = suc;
        }
    }

    while (t--) {
        solve();
    }

    return 0;
}
