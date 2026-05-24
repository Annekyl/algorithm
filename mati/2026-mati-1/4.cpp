#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mp[n + 1];             // 存最近一次出现x的下标
    set<int> st;               // 存当前有哪些数
    vector<int> len(n + 1, 1); // 以i为结尾的子序列长度
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        auto it = st.lower_bound(x);
        if (it == st.begin()) {
            // 没有找到小于x的数

        } else {
            it--;
            int pos = mp[*it];
            len[i] = len[pos] + 1;
        }
        if (st.find(x) == st.end()) {
            st.insert(x);
            mp[x] = i;
        } else {
            mp[x] = i;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < 3) {
            cout << "No" << endl;
            continue;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}