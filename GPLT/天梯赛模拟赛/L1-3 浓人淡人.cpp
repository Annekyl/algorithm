#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n;
    cin >> n;
    cout << n << endl;
    if (n < 0)
        cout << "dan ren" << endl;
    else if (n == 0)
        cout << "xian ren" << endl;
    else
        cout << "nong ren" << endl;

    return 0;
}