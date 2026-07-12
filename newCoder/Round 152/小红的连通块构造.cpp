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
    int k;
    cin >> k;
    if (k > 21)
        cout << -1 << endl;
    else {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 6; j++) {
                if (i % 2 == j % 2) {
                    if (k) {
                        k--;
                        cout << 1;
                    } else {
                        cout << 0;
                    }
                } else {
                    cout << 0;
                }
            }
            cout << endl;
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
