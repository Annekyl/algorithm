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
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    deque<int> q;
    int cnt = 0, ans = INF;
    int st, ed;
    for (int i = 1; i <= n; i++) {
        q.push_back(i);
        mp[a[i]]++;
        if (mp[a[i]] == 1) {
            cnt++;
        }

        while (q.size() && mp[a[q.front()]] > 1) {
            mp[a[q.front()]]--;
            q.pop_front();
        }
        if (cnt == m) {
            if (ans > i - q.front() + 1) {
                ans = min(ans, i - q.front() + 1);
                st = q.front();
                ed = i;
            }
        }
    }
    cout << st << ' ' << ed << endl;
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
