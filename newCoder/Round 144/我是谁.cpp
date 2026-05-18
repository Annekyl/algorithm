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
    int cnt[4] = {0};
    string s;
    cin >> s;
    for (auto &c : s) {
        cnt[c - 'A']++;
    }
    bool suc = true;
    int num = n / 4;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] != num) {
            suc = false;
            break;
        }
    }
    if (suc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
