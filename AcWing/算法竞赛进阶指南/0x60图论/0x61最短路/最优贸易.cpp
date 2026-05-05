#include "bits/stdc++.h"

#define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;
int a[N];
int min_d[N], max_d[N];
int v[N];

// 边要开大一些，因为要存双向边
int ver[N * 15], edge[N * 15], head[N], ne[N * 15], tot = 1;
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z;
    ne[tot] = head[x], head[x] = tot;
}

void spfa(int *d, int st, int rec) {
    d[st] = a[st];
    queue<int> q;
    q.push(st);
    v[st] = 1;

    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i], z = edge[i];
            if (z != rec && z != 2)
                continue;
            int val = rec == 1 ? min(d[x], a[y]) : max(d[x], a[y]);
            if ((rec == 1 && val < d[y]) || (rec == -1 && val > d[y])) {
                d[y] = val;
                if (!v[y]) {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z == 1 ? -1 : z);
    }

    memset(min_d, 0x3f, sizeof min_d);
    memset(max_d, 0xcf, sizeof max_d);
    spfa(min_d, 1, 1);
    spfa(max_d, n, -1);

    // for (int i = 1; i <= n; i++) {
    //     cout << min_d[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, max_d[i] - min_d[i]);
    }
    cout << ans;
    return 0;
}