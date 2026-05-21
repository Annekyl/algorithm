#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> weapon(n);
    vector<pii> tool(m);
    for (int i = 0; i < n; i++) {
        cin >> weapon[i].first;
        weapon[i].second = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> tool[i].second >> tool[i].first;
    }
    sort(weapon.begin(), weapon.end());
    reverse(weapon.begin(), weapon.end());
    sort(tool.begin(), tool.end());
    reverse(tool.begin(), tool.end());

    int idx = 0;
    multiset<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (idx < m && tool[idx].first >= weapon[i].first) {
            st.insert(tool[idx].second);
            idx++;
        }

        if (st.size()) {
            auto it = st.upper_bound(weapon[i].second);
            if (it != st.begin()) {
                it--;
                ans += weapon[i].first;
                st.erase(it);
            }
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}