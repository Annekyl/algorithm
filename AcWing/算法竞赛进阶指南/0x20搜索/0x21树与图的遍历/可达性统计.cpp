#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 3e4 + 10;

int n, m;
int a[N];    // 拓扑序列
int cnt = 0; // 拓扑序列的长度
bitset<N> f[N];

int ver[N], ne[N], head[N], tot = 1;
int deg[N]; // 节点的度
void add(int x, int y) {
    ver[++tot] = y;
    ne[tot] = head[x], head[x] = tot;
    deg[y]++;
}

// 求拓扑序列
void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        a[++cnt] = x;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i];
            if (--deg[y] == 0) {
                q.push(y);
            }
        }
    }
}

void calc() {
    for (int i = n; i >= 1; i--) {
        int x = a[i];
        f[x][x] = 1;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i];
            f[x] |= f[y];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    topsort();
    calc();
    for (int i = 1; i <= n; i++) {
        cout << f[i].count() << endl;
    }
    return 0;
}