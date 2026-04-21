#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 32010;

int n, tr[N];
int level[N];

int lowbit(int x) { return x & -x; }

int quary(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

void add(int x) {
    for (int i = x; i <= N; i += lowbit(i))
        tr[i]++;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x++;
        level[quary(x)]++;
        add(x);
    }
    for (int i = 0; i < n; i++) {
        cout << level[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}