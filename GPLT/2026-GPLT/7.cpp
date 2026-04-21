#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mx = 0, mn = 1e6, sum=0, avg;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        sum += a[i];
    }
    avg = sum / n;
    cout << mx << " " << mn << " " << avg << endl;
    bool suc = true;
    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] > avg * 2) {
            if (!first)
                cout << " ";
            cout << i;
            suc = false;
            first = false;
        }
    }
    if (suc)
        cout << "Normal" << endl;
    return 0;
}
