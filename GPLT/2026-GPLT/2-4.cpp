#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

const int N = 1e4 + 10;
vector<pii> g[N];
set<int> path;
vector<int> res;

void dfs(int st) {
    bool suc = false;
    int mx = 0, idx;
    for (auto [y, v] : g[st]) {
        if (path.find(y) != path.end())
            continue;
        if (v > mx) {
            mx = v;
            idx = y;
        } else if (v == mx) {
            idx = min(idx, y);
        }
    }
    if (mx == 0) {
        return;
    } else {
        path.insert(idx);
        res.push_back(idx);
        dfs(idx);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int id1, id2, p;
        cin >> id1 >> id2 >> p;
        g[id1].push_back({id2, p});
    }
    int k;
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        path.insert(x);
        res.push_back(x);
        dfs(x);

        for (int i = 0; i < res.size(); i++) {
            if (i)
                cout << "->";
            cout << res[i];
        }
        cout << endl;

        path.clear();
        res.clear();
    }

    return 0;
}
