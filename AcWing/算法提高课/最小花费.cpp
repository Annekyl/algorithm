#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, double>> g[n + 1];
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        double t = (100.0 - z) / 100.0;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << ':';
    //     for (auto [x, z] : g[i]) {
    //         cout << x << ',' << z << ' ';
    //     }
    //     cout << endl;
    // }

    int a, b;
    cin >> a >> b;

    auto dijkstra = [&]() -> double {
        priority_queue<pair<double, int>> q;
        vector<double> d(n + 1, 0);
        vector<bool> v(n + 1, false);
        q.push({1.0, a});
        d[a] = 1.0;

        while (q.size()) {
            auto [dist, x] = q.top();
            q.pop();
            if (v[x])
                continue;
            v[x] = true;
            for (auto [y, z] : g[x]) {
                if (v[y])
                    continue;
                d[y] = max(d[y], d[x] * z);
                q.push({d[y], y});
            }
        }

        return d[b];
    };
    double ans = dijkstra();
    printf("%.8lf", 100.0 / ans);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
