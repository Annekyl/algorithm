#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    int diff = 0;
    int st = -1;
    vi zero, one;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (st == -1)
                st = i + 1;
            if (s[i] == '0')
                zero.push_back(i + 1);
            if (s[i] == '1')
                one.push_back(i + 1);
            diff++;
        }
    }
    if (diff == 0)
        cout << 0 << endl;
    else {
        cout << diff + 1 << endl;
        for (int i = 0; i < one.size(); i++) {
            cout << one[i] << endl;
            cout << zero[i] << endl;
        }
        cout << one[0] << endl;
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
