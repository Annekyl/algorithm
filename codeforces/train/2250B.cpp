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
    int n, k;
    cin >> n >> k;
    int mx = (n + 1) / 2 - 1 + n - (n + 1) / 2 - 1;
    if (k > mx)
        cout << -1 << endl;
    else {
        if (k & 1) {
            // 奇数对
            int cnt1 = (k + 1) / 2, cnt0 = (k + 1) / 2 + 1;
            for (int i = 0; i < cnt1; i++)
                cout << 1;
            for (int i = 0; i < cnt0; i++)
                cout << 0;
            for (int i = cnt1 + cnt0 + 1; i <= n; i++) {
                if (i & 1)
                    cout << 0;
                else
                    cout << 1;
            }

        } else {
            // 偶数对
            int cnt1 = k / 2 + 1, cnt0 = k / 2 + 1;
            for (int i = 0; i < cnt1; i++)
                cout << 0;
            for (int i = 0; i < cnt0; i++)
                cout << 1;
            for (int i = cnt1 + cnt0 + 1; i <= n; i++) {
                if (i & 1)
                    cout << 0;
                else
                    cout << 1;
            }
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
