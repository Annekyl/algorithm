#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
int fa[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    x = get(x), y = get(y);
    fa[x] = y;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    init();
    for (int i = 1; i <= n; i++) {
        if (x + i <= n)
            merge(i, x + i);
        if (y + i <= n)
            merge(i, y + i);
    }

    bool suc = true;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (get(x) != get(i))
            suc = false;
    }

    if (suc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}