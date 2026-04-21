#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

vector<pii> g[N];
int ans = 0;
vector<int> res;

void dfs(int st, int mn) {
    // 到达终点
    if (g[st].size() == 0) {
        // cout << st << ":" << mn << endl;
        if (mn > ans) {
            ans = mn;
            res.clear();
            res.push_back(st);
        } else if (mn == ans) {
            res.push_back(st);
        }
        return;
    }

    for (auto [y, v] : g[st]) {
        // mn = min(mn, v);
        dfs(y, min(mn, v));
    }
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, v;
        cin >> x >> v;
        g[x].push_back({i, v});
    }

    // for (int i = 0; i <= n; i++) {
    //     for (auto [x, v] : g[i]) {
    //         cout << i << " " << x << "," << v << endl;
    //     }
    //     // cout << endl;
    // }

    dfs(0, INF);
    cout << ans << endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (i)
            cout << " ";
        cout << res[i];
    }

    return 0;
}
