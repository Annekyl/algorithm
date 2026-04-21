#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }

    int get(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }

    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        fa[x] = y;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vector<pii> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }

    // 检查是否可能存在与之对应的点
    int cntA = 0, cntB = 0, cntC = 0, cntD = 0;
    for (char c : s) {
        if (c == 'A')
            cntA++;
        if (c == 'B')
            cntB++;
        if (c == 'C')
            cntC++;
        if (c == 'D')
            cntD++;
    }
    if ((cntA == 0 && cntB > 0) || (cntB == 0 && cntA > 0) ||
        (cntC == 0 && cntD > 0) || (cntD == 0 && cntC > 0)) {
        cout << "No" << endl;
        return 0;
    }

    // 给边进行分类
    vector<pii> ab, cd, cross;
    for (auto [u, v] : g) {
        char c1 = s[u], c2 = s[v];

        if ((c1 == 'A' || c1 == 'B') && (c2 == 'A' || c2 == 'B')) {
            ab.push_back({u, v});
        } else if ((c1 == 'C' || c1 == 'D') && (c2 == 'C' || c2 == 'D')) {
            cd.push_back({u, v});
        } else {
            cross.push_back({u, v});
        }
    }

    // 检查AB连通性
    if (cntA > 0 && cntB > 0) {
        DSU dsu(n + 1);
        for (auto [u, v] : ab)
            dsu.merge(u, v);

        int fa = -1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'A' || s[i] == 'B') {
                if (fa == -1)
                    fa = dsu.get(i);
                else if (fa != dsu.get(i)) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    // cout << 123 << endl;

    // 检查CD连通性
    if (cntC > 0 && cntD > 0) {
        DSU dsu(n + 1);
        for (auto [u, v] : cd)
            dsu.merge(u, v);

        int fa = -1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'C' || s[i] == 'D') {
                if (fa == -1)
                    fa = dsu.get(i);
                else if (fa != dsu.get(i)) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    // 构造生成树
    vector<pii> ans;
    DSU dsu(n + 1);
    for (auto [u, v] : ab) {
        if (dsu.merge(u, v)) {
            ans.push_back({u, v});
        }
    }
    for (auto [u, v] : cd) {
        if (dsu.merge(u, v)) {
            ans.push_back({u, v});
        }
    }
    for (auto [u, v] : cross) {
        if (dsu.merge(u, v)) {
            ans.push_back({u, v});
        }
    }

    if (ans.size() != n - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (auto [u, v] : ans) {
            cout << u << " " << v << endl;
        }
    }

    return 0;
}