#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> temp = a;
    sort(temp.begin(), temp.end());

    // for (int i = 0; i < n; i++) {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int mx = temp[n - 1]; // 用最大值当中间元素实现交换
    int mn;               // 需要交换的最小元素
    for (int i = 0; i < n; i++) {
        if (temp[i] != a[i]) {
            // cout<<i<<":"<<temp[i]<<endl;
            mn = temp[i];
            break;
        }
    }
    // debug(mx);
    // debug(mn);
    while (q--) {
        int x;
        cin >> x;
        if (x > mn * mx) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
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
