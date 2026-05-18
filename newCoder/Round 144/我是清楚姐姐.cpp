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
    int n;
    cin >> n;
    if (n >= 4)
        cout << -1 << endl;
    else {
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << 1 << " " << 2 << endl;
            cout << 3 << " " << 4 << endl;
        } else {
            cout << 1 << " " << 2 << " " << 3 << endl;
            cout << 5 << " " << 4 << " " << 6 << endl;
            cout << 7 << " " << 8 << " " << 9 << endl;
        }
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
