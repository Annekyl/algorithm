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

void solve() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);

    if (n == m) {
        cout << 0 << ' ';
        cout << 8;
        for (int i = 1; i < m; i++) {
            cout << 9;
        }
        return;
    }

    int d = n - m;
    // 输出最小值
    for (int i = 1; i < d; i++) {
        cout << 9;
    }
    if (d > 1)
        for (int i = 1; i < m; i++) {
            cout << 0;
        }
    cout << 1;

    cout << " ";

    // 输出最大值
    for (int i = 0; i < d; i++) {
        cout << 9;
    }
    cout << 8;
    for (int i = 1; i < m; i++) {
        cout << 9;
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
