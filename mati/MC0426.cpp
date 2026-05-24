#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vi g(26, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s[s.size() - 1] - 'a';
        g[x] |= (1 << y);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            if ((g[i] >> k) & 1) {
                g[i] |= g[k];
            }
        }
    }

    while (q--) {
        char c1, c2;
        cin >> c1 >> c2;
        int x = c1 - 'a', y = c2 - 'a';
        if ((g[x] >> y) & 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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