#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    // cout << (int)'a' << " " << (int)'A' << endl;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char &c = s[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }
    if (s == "ovo") {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
