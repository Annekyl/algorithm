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
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];

    if (n % 3) {
        cout << -1 << endl;
        return;
    }

    string target[6][2] = {{"111", "000"}, {"000", "111"}, {"110", "100"},
                           {"100", "110"}, {"011", "001"}, {"001", "011"}};

    auto cost = [&](int st, int tar) -> int {
        int res = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][st + j] != target[tar][i][j])
                    res++;
            }
        }
        return res;
    };

    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; i += 3) {
        if (i / 3 % 2 == 0) {
            c1 += cost(i, 0);
            c2 += cost(i, 1);
        } else {
            c1 += cost(i, 1);
            c2 += cost(i, 0);
        }
        c3 += min(cost(i, 2), cost(i, 3));
        c4 += min(cost(i, 4), cost(i, 5));
    }
    cout << min({c1, c2, c3, c4}) << endl;
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
