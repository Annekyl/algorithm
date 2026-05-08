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

int calc(int x) {
    if (x < 2)
        return 0;
    int idx1 = -1, idx2 = -1;
    for (int i = 63; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (idx1 == -1)
                idx1 = i;
            else if (idx2 == -1)
                idx2 = i;
            else
                break;
        }
    }

    int cnt1 = idx1;
    // 从低于最高位的位上随便选两个为1
    int cnt2 = idx1 * (idx1 - 1) / 2;
    // 存在两个1时，可以用第0位选到第idx2位
    if (idx2 != -1) {
        cnt2 += idx2 + 1;
    }

    return cnt1 + cnt2;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = calc(r);
    if (l > 0) {
        ans -= calc(l - 1);
    }
    cout << ans << endl;
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
