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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    auto search_r = [&](int x) {
		
    };

    int q;
    cin >> q;
    while (q--) {
        int st, ed;
        cin >> st >> ed;
        pii temp1 = {st, st}, temp2 = {ed, ed};
        auto it1 = lower_bound(a.begin(), a.end(), temp1);
        auto it2 = upper_bound(a.begin(), a.end(), temp2);
        if (it2 == a.begin()) {
            cout << "No" << endl;
            continue;
        }
        it2--;
        if (it2 - it1 + 1 < 2) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
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
