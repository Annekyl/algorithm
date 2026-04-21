#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;

void solve() {
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            a.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << a.size() << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}