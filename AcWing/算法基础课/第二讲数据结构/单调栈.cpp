#include "bits/stdc++.h"

#define int long long
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

int n;
int a[N];
int ans[N];
stack<int> stk;

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    ans[1] = -1;
    stk.push(a[1]);
    FOR(i, 2, n) {
        int x = a[i];
        while (stk.size() && stk.top() >= x)
            stk.pop();
        if (stk.size()) {
            ans[i] = stk.top();
            stk.push(x);
        } else {
            ans[i] = -1;
            stk.push(x);
        }
    }
    FOR(i, 1, n) cout << ans[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}