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
    string s;
    cin >> s;
    int m;
    cin >> m;
    string ans;
    int x = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            x = x * n + (c - '0');
        } else {
            x = x * n + (c - 'A' + 10);
        }
    }
    // cout << x << endl;
    while (x) {
        int add = x % m;
        if (add < 10)
            ans += ('0' + add);
        else
            ans += (add - 10 + 'A');
        x /= m;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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
