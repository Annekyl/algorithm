#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, x;
    cin >> n >> x;
    vi a;
    for (int i = (x + 1) / 2; i <= n; i++) {
        a.push_back(i);
    }
    // for (int i = x; i <= n; i++) {
    //     a.push_back(i);
    // }
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}