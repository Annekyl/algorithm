#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 3e4 + 10;

int fa[N];
int d[N];
int sz[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
        d[i] = 0;
        sz[i] = 1;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    fa[x] = root;
    return root;
}

void merge(int x, int y) {
    int rx = get(x), ry = get(y);
    if (rx == ry)
        return;
    fa[rx] = ry;
    d[rx] = sz[ry];
    sz[ry] += sz[rx];
}

void solve() {
    init();
    int t;
    cin >> t;
    while (t--) {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'M') {
            merge(i, j);
        } else {
            if (get(i) != get(j))
                cout << -1 << endl;
            else {
                int ans = abs(d[i] - d[j]) - 1;
                if (ans < 0)	// ⚠️防止i==j时输出-1
                    cout << 0 << endl;
                else
                    cout << ans << endl;
            }
        }
    }
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
