#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

int fa[N];

class DisArr {
  private:
    vector<int> a;
    bool is_sort;
	
    void process() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

  public:
    void add(int x) {
        a.push_back(x);
        is_sort = false;
    }

    int get_pos(int x) {
        if (!is_sort)
            process();
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    int get_value(int pos) {
        if (!is_sort)
            process();
        return a[pos - 1];
    }

    int get_sz() {
        if (!is_sort)
            return false;
        return a.size();
    }
};

class DSU {
  private:
    vector<int> fa, d;
    void init(int n) {
        fa.resize(n + 1);
        d.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            d[i] = 0;
        }
    }

  public:
    DSU(int n) { init(n); }
    int get(int x) {
        if (x == fa[x])
            return x;
        int root = get(fa[x]);
        d[x] ^= d[fa[x]];
        return fa[x] = get(fa[x]);
    }

    bool merge(int x, int y, int w) {
        int rx = get(x), ry = get(y);
        if (rx == ry)
            return (d[x] ^ d[y]) == w;
        fa[rx] = ry;
        d[rx] = d[x] ^ d[y] ^ w;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DisArr a;
    DSU dsu(m * 2 + 1);
    vector<tuple<int, int, int>> quary;
    for (int i = 1; i <= m; i++) {
        int l, r, w;
        string s;
        cin >> l >> r >> s;
        if (s == "even")
            w = 0;
        else
            w = 1;
        a.add(l - 1);
        a.add(r);
        quary.push_back({l - 1, r, w});
    }

    int ans = 0;
    for (auto [x, y, w] : quary) {
        x = a.get_pos(x), y = a.get_pos(y);
        if (!dsu.merge(x, y, w)) {
            break;
        }
        ans++;
    }
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
