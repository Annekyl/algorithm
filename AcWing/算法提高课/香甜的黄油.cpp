#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int n, p, c;
    cin >> n >> p >> c;
    vector<int> cnt(p + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<pii> g[p + 1];
    while (c--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    auto dijkstra = [&](int st) -> int {
        vector<int> d(p + 1, 0x3f3f3f3f);
        d[st] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<bool> v(p + 1, false);
        q.push({0, st});

        while (q.size()) {
            auto [dist, x] = q.top();
            q.pop();
            v[x] = true;
            for (auto [y, z] : g[x]) {
                if (v[y])
                    continue;
                d[y] = min(d[y], d[x] + z);
                q.push({d[y], y});
            }
        }

        int res = 0;
        for (int i = 1; i <= p; i++) {
            res += d[i] * cnt[i];
        }
        // cout<<res<<endl;
        return res;
    };

    int ans = 1e9;
    for (int i = 1; i <= p; i++)
        ans = min(ans, dijkstra(i));
    cout << ans << endl;
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
