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
    map<char, pii> mp;
    for (int i = 1; i <= n; i++) {
        char d;
        int q;
        cin >> d >> q;
        if (mp.find(d) == mp.end()) {
            mp[d] = {q, i};
        } else {
            if (q > mp[d].first) {
                mp[d] = {q, i};
            }
        }
    }
    if (mp.size() < 6) {
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    for (auto [d, temp] : mp) {
        auto [q, idx] = temp;
        if (q < 60) {
            cout << -1 << endl;
            return;
        }
        sum += q;
    }
    if (sum < 70 * 6) {
        cout << -1 << endl;
        return;
    }
    for (auto [d, temp] : mp) {
        auto [q, idx] = temp;
        cout << idx << ' ';
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
