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
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (c--) {
            string s;
            cin >> s;
            mp[s]++;
        }
    }
    vector<string> ans;
    for (auto [s, cnt] : mp) {
        if (cnt == n)
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto s : ans)
        cout << s << endl;
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
