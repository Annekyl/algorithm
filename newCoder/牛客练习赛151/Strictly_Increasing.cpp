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

int n;

void solve() {
    cin >> n;
    int a[n];
    bool suc = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < i)
            suc = false;
    }

    a[0] = 0;
    for (int i = 1; i < n; i++) {
        int target = a[i - 1] + 1; // 目标值
        // 当前值可以变的最大值
        int mx = a[i] / 2;
        if (a[i] % 2 == 0)
            mx--;
        if (mx >= target) {
            a[i] = target;
            // continue;
        } else {
            // 当前值保持默认值
            if (a[i] <= a[i - 1]) {
                suc = false;
                break;
            }
        }
        // cout << a[i] << " ";
    }
    if (!suc) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
