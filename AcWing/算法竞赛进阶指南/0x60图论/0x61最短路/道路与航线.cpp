#include "bits/stdc++.h"

#define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 2e5 + 10;

int t, r, p, s;

int ver[N], edge[N], ne[N], head[N], tot = 1;
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z;
    ne[tot] = head[x], head[x] = tot;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> r >> p >> s;
    for (int i = 1; i <= r; i++) {
        int x, y, z;
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    return 0;
}