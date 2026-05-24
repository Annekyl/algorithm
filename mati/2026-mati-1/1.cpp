#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
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