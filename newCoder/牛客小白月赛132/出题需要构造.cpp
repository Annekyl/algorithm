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
    if (n != m || n == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << 2 << endl;
    // 每一行、每一列都是一个全排列
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (i + j - 1) % n + 1 << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
