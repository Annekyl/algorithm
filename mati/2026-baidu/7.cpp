#include "bits/stdc++.h"
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1, sum = 0;
    int cnt = 0;      // 未知的人数
    bool dup = false; // 已知的最高票数是否重复
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // mx = max(mx, a[i]);
        if (mx < a[i]) {
            mx = a[i];
            dup = false;
        } else if (mx == a[i]) {
            dup = true;
        }
        if (a[i] != -1)
            sum += a[i];
        else
            cnt++;
    }
    bool ys = true; // 是否为原数组有的数字

    if (cnt != 0) {
        int temp =
            (n - sum + cnt - 1) / cnt; // 未知的人中最高票数的人票数最低是多少
        // if ((n - sum) % cnt == 0)
        //     temp++;
        if (temp > mx) {
            mx = temp;
            if ((n - sum) % cnt != 1 && cnt > 1)
                mx++;
            ys = false;
        } else if (temp == mx) {
            mx++;
            ys = false;
        } else {
            // cout << mx << endl;
            if (dup) {
                mx++;
                ys = false;
            }
        }
        // cout << temp << " " << mx << " " << ys << endl;
    }

    // mx = max(mx, (n - sum + cnt - 1) / cnt);
    for (int i = 0; i < n; i++) {
        if (a[i] >= mx) {
            cout << i + 1 << ' ';
        } else if (a[i] == -1) {
            // cout << n - sum << ' ' << mx << ' ' << ys << endl;
            if (n - sum > mx && ys)
                cout << i + 1 << ' ';
            else if (n - sum >= mx && !ys)
                cout << i + 1 << ' ';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}