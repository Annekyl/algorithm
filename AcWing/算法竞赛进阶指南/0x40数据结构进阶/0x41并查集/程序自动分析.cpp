#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

struct rec {
    int i, j;
    bool e;
};

int n;
rec a[N];
int b[N * 2]; // 离散化数组
int cnt;      // 离散化后的数组长度

int fa[N * 2];

// 初始化并查集
void init() {
    for (int i = 1; i <= cnt; i++) {
        fa[i] = i;
    }
}

// 查找并查集父节点
int get(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

// 并查集合并，x合并到y
void merge(int x, int y) { fa[get(x)] = get(y); }

// 查找离散化后的索引
int query(int x) { return lower_bound(b + 1, b + cnt + 1, x) - b; }

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].i >> a[i].j >> a[i].e;
        b[i * 2 - 1] = a[i].i;
        b[i * 2] = a[i].j;
    }

    // 离散化
    sort(b + 1, b + 2 * n + 1);
    cnt = unique(b + 1, b + 2 * n + 1) - (b + 1);

    // 处理每对关系
    init();
    for (int i = 1; i <= n; i++) {
        if (a[i].e == 1) {
            merge(query(a[i].i), query(a[i].j));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i].e == 0) {
            if (get(query(a[i].i)) == get(query(a[i].j))) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}