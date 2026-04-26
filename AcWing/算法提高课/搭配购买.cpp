#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e4 + 10;

int fa[N];
int w[N], v[N]; // w: 价钱 v: 价值

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
        return;
    v[y] += v[x];
    w[y] += w[x];
    fa[x] = y;
}

void solve() {
    init();
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // 并查集将同一类先整理为一个物品，记录价钱和价值
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (get(i) != i)
            continue;
        a.push_back(i);
    }

    // for (int x : a)
    //     cout << w[x] << ' ' << v[x] << endl;

    // exit(0);

    // DP求最大价值
    int dp[s + 1];
    memset(dp, 0, sizeof dp);
    for (int idx : a) {
        for (int j = s; j >= w[idx]; j--) {
            dp[j] = max(dp[j], dp[j - w[idx]] + v[idx]);
        }
    }
    cout << dp[s] << endl;
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
