#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n + 1];
    int cnt[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    while (m--) {
        string t;
        cin >> t;
        int len = t.size();
        for (int i = 1; i <= n; i++) {
            string ss = s[i].substr(0, len);
            if (ss == t)
                cnt[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
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