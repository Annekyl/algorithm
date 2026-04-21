#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int a[9];
    for (int i = 0; i < 9; i++)
        cin >> a[i];
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;
        } else {
            a[i + 1] += a[i] / 3;
            a[i] %= 3;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (i)
            cout << " ";
        cout << a[i];
    }
    return 0;
}