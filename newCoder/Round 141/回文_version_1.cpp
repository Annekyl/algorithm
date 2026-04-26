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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;

void solve() {
    // cin >> n;
    string s;
    cin >> s;
    bool suc = true;
    for (int i = 0; i <= s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            suc = false;
            break;
        }
    }
    int x = stoi(s);
    int temp = sqrt(x);
    if (temp * temp == x) {
        s = to_string(temp);
        for (int i = 0; i <= s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                suc = false;
                break;
            }
        }
    } else {
        suc = false;
    }

    if (suc)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
