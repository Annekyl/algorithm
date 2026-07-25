#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void db(int x) {
    int mn = x, i, j, k;
    for (int a = 0; a <= x; a++) {
        for (int b = 0; b <= x; b++) {
            for (int c = 0; c <= x; c++) {
                if (a * b + c == x) {
                    int u = max(a, max(b, c)), d = min(a, min(b, c));
                    if (u - d < mn) {
                        mn = u - d;
                        i = a, j = b, k = c;
                    }
                }
            }
        }
    }
    cout << mn << ' ';
    // cout << x << ' ' << mn << endl;
    // cout << x << endl << i << ' ' << j <<' ' << k << ' ' << mn << endl;
}

void solve() {
    int x;
    cin >> x;
    x++;
    int l = 0, r = 1e9;
    while (l + 1 < r) {
        // cout << l << ' ' << r << endl;
        int mid = (l + r) >> 1;
        if (mid * mid + mid >= x)
            r = mid;
        else
            l = mid;
    }
    int n = r;
    x -= n * n - n;
    // cout << n << ' ' << x << endl;
    if (x == 1)
        cout << 0 << endl;
    // else if (x <= n)
    //     cout << min(x - 1, n - x) + 1 << endl;
    // else {
    //     cout << min(x - n - 1, 2 * n - x) + 1 << endl;
    // }
    else if (x <= n) {
        x -= 1;
        cout << min(x, n - x + 1) << endl;
    } else {
        x -= n;
        cout << min(x, n - x + 1) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}