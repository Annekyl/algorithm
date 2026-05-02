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
string s1, s2;
int x, y, d;

int get(string s) {
    int res = 0;
    int p = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1')
            res += p;
        p *= 2;
    }
    return res;
}

void solve() {
    // cin >> n;
    cin >> s1 >> s2;
    x = get(s1), y = get(s2);
    d = abs(x - y);
    if (x == 0 && y != 0)
        cout << -1 << endl;
    else
        cout << d << endl;
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
