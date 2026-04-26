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
        int l = i, r = s.size() - 1 - i;
        if (s[l] != s[r]) {
            if (s[l] == 'n') {
                if (s[l + 1] != 'n') {
                    // cout << 1 << endl;
                    suc = false;
                    break;
                }
                s[l] = 'm';
                s.erase(s.begin() + l + 1);
            } else {
                if (s[r - 1] != 'n') {
                    // cout << 2 << endl;

                    suc = false;
                    break;
                }
                s[r] = 'm';
                s.erase(s.begin() + r - 1);
            }
        }
    }

    if (suc) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
