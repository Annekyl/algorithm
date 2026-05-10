#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &aa : a)
        cin >> aa;
    sort(a.begin(), a.end());
    int mx = 1;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if ((a[l] + a[r]) % 2)
                continue;
            int x = (a[l] + a[r]) / 2;
            int id1 = lower_bound(a.begin(), a.end(), x) - a.begin();
            int id2 = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
            if (a[id1] != x)
                continue;
            int mid = (r + l) / 2;
            if (id1 <= mid && mid <= id2)
                mx = max(mx, r - l + 1);
            else if (mid < id1) {
                mx = max(mx, 2 * (r - id1) + 1);
            } else
                mx = max(mx, 2 * (id2 - l) + 2);
        }
    }
    cout << mx << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}