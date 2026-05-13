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
    int n, R;
    cin >> n >> R;
    cout << n;
    string ans;
    char digits[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    if (n == 0) {
        ans = "0";
    } else {
        while (n) {
            if (n % R < 0) {
                ans += digits[n % R - R];
                n = n / R + 1;
            } else {
                ans += digits[n % R];
                n = n / R;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "=" << ans << "(base" << R << ")" << endl;
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
