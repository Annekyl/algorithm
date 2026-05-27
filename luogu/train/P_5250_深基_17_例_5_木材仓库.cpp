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
    int m;
    cin >> m;
    set<int> st;
    while (m--) {
        int op, len;
        cin >> op >> len;
        if (op == 1) {
            if (st.find(len) != st.end()) {
                cout << "Already Exist" << endl;
            } else {
                st.insert(len);
            }
        } else {
            if (st.empty()) {
                cout << "Empty" << endl;
            } else {
                auto it = st.lower_bound(len);
                if (it == st.begin()) {
                    cout << *it << endl;
                    st.erase(it);
                } else {
                    auto pre_it = it;
                    pre_it--;
                    if (abs(*pre_it - len) <= abs(*it - len)) {
                        cout << *pre_it << endl;
                        st.erase(pre_it);
                    } else {
                        cout << *it << endl;
                        st.erase(it);
                    }
                }
            }
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
