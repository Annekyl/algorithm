#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

vector<pii> a;

bool check(int mid, int x) { return a[mid].first > x; }

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    int mx = a[n - 1].first;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= mx) {
            if (!first)
                cout << " ";
            cout << a[i].second;
            first = false;
        }
    }
    cout << endl;
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        int l = 0, r = n;
        // auto it = upper_bound(a.begin(), a.end(), x);
        // if (it == a.end()) {
        //     cout << 0 << endl;
        // } else {
        //     cout << (*it).second << endl;
        // }
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid, x)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l >= n) {
            cout << 0 << endl;
        } else {
            cout << a[l].second << endl;
        }
    }
    return 0;
}
