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

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    int ans = 0;
    vector<int> sz(n + 1, 1);
    while (q.size()) {
        int x = q.front();
        q.pop();

        for (int y : g[x]) {
            if (a[x] == a[y]) {
                ans += sz[x];
                sz[y] += sz[x];
            }
            q.push(y);
        }
    }
	cout<<ans<<endl;
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
