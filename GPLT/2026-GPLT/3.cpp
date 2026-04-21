#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;
    int res = b - a;
    cout << res << endl;
    if (res > 250) {
        cout << "jiu ting tu ran de..." << endl;
    } else if (res <= 0) {
        cout << "hai sheng ma?" << endl;
    } else {
        cout << "nin tai cong ming le!" << endl;
    }
    return 0;
}
