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
priority_queue<int> q;

void solve() {
    cin >> n;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        q.push(-x);
    }

    int ans = 0;
    while (q.size() > 1) {
        int a = -q.top();
        q.pop();
        int b = -q.top();
        q.pop();
        ans += a + b;
        q.push(-(a + b));
    }
    cout << ans;
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