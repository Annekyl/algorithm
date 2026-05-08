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
    int p[n + 1];
    int cntL[n + 1] = {0};
    vi cntR(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (stk.size() && p[stk.top()] < p[i])
            stk.pop();
        if (stk.size())
            cntL[i] = stk.top();
        stk.push(i);
        // cout << "i:" << i << ",cntL:" << cntL[i] << endl;
    }
    // cout << "cntL:" << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << cntL[i] << ' ';
    // cout << endl;

    while (stk.size())
        stk.pop();
    for (int i = n; i >= 1; i--) {
        while (stk.size() && p[stk.top()] < p[i])
            stk.pop();
        if (stk.size())
            cntR[i] = stk.top();
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int szL = i - cntL[i], szR = cntR[i] - i;
        int ans = szL * (n - i + 1) + szR * i - szL * szR;
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
