#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    string s;
    string res;
    while (getline(cin, s)) {
        res += to_string(s.size());
    }
    cout << res << endl;
    return 0;
}
