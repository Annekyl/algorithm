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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    for (int _ = 1; _ < n; _++) {
        int x = (a[l].first + a[r].first) / 2;
        int upper = 0;
        if ((a[l].first + a[r].first) % 2 == 1) {
            pii temp = {x, n};
            upper = upper_bound(a.begin(), a.end(), temp) - a.begin();
        } else {
            pii temp = {x, n};
            upper = lower_bound(a.begin(), a.end(), temp) - a.begin();
        }
        // debug(upper);
        upper = r - upper + 1;
        // debug(x);
        // debug(upper);

        int len = r - l + 1;
        if (upper * 2 >= len) {
            r--;
        } else {
            l++;
        }
    }
    cout << l << " " << r << endl;
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
