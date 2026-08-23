#include "bits/stdc++.h"
#define int long long

using namespace std;

void solve() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (s >= a[i].first)
            s += a[i].second;
        else {
            while (s < a[i].first && k > 0) {
                s *= 2;
                k--;
            }
            if (s < a[i].first)
                break;
            else
                s += a[i].second;
        }
    }
    while (k > 0) {
        s *= 2;
        k--;
    }
    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}