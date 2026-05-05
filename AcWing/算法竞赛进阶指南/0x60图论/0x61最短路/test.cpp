#include "bits/stdc++.h"

using namespace std;

constexpr int N = 1e6 + 10;

int n, m;
int a[N];
int mx[N], mn[N];
int v[N];

// 边开大一些，存的正反两个图
int ver[N], edge[N], ne[N], head[N], tot = 1;

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
            if (z == 2 || z == rec) {
                int val = rec == 1 ? min(d[x], a[y]) : max(d[x], a[y]);
                if (rec == 1 && val < d[y] || rec == -1 && val > d[y]) {
                    d[y] = val;
                    if (!v[y]) {
                        q.push(y);
                        v[y] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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

    memset(mn, 0x3f, sizeof mn);
    spfa(mn, 1, 1);
    memset(mx, 0xcf, sizeof mx);
    spfa(mx, n, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, mx[i] - mn[i]);
    }
    cout << ans << endl;
    return 0;
}