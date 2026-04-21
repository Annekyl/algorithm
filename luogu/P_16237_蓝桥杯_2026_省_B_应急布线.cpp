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

int n, m;
int fa[N];
int sz[N];
int line[N];

void init() {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        line[i] = 0;
        sz[i]++;
    }
}

int get(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int a, int b) {
    if (a == b)
        return;
    a = get(a), b = get(b);
    if (a < b)
        swap(a, b);

    sz[b] += sz[a];
    fa[a] = b;
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        line[a]++, line[b]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i)
            ans++;
    }
    cout << ans << " ";
    if (ans == 0) {
        cout << 0 << endl;
        return;
    }

    priority_queue<pii, vector<pii>, greater<pii>> q[n + 1];
    for (int i = 1; i <= n; i++) {
        int f = get(i);
        q[f].push({line[i], i});
    }

    int temp_line[n + 1];
    for (int i = 1; i <= n; i++) {
        temp_line[i] = line[i];
    }

    for (int i = 1; i <= n; i++) {
        int f = get(i);
        if (f == 1)
            continue;

        auto [fline, fid] = q[f].top();
        q[f].pop();
        auto [line1, id1] = q[1].top();
        q[1].pop();
        merge(1, f);
        line[fid]++;
        line[id1]++;
        q[1].push({line[id1], id1});
        q[1].push({line[fid], fid});
        while (q[f].size()) {
            auto [cnt, id] = q[f].top();
            q[f].pop();
            q[1].push({cnt, id});
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, line[i] - temp_line[i]);
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
