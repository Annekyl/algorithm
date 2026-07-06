// 二分图匹配
// 匈牙利算法 / 最大流求二分图匹配
// AcWing 861. 二分图的最大匹配
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int u) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!st[v]) {
            st[v] = true;
            if (match[v] == 0 || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

// 匈牙利算法
int hungarian() {
    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    return res;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    printf("%d\n", hungarian());

    return 0;
}
