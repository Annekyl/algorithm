#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;
string s;
int y, n;

bool valid(int x) {
    set<int> st;
    if (x < 1000)
        st.insert(0);
    s = to_string(x);
    while (x) {
        st.insert(x % 10);
        x /= 10;
    }
    while (s.size() < 4)
        s = "0" + s;
    return st.size() == n;
}

signed main() {
    cin >> y >> n;
    for (int i = 0;; i++) {
        if (valid(y + i)) {
            cout << i << " " << s << endl;
            break;
        }
    }

    return 0;
}