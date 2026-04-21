#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 51;

int n, m;
int v[N];
vector<int> a;

void dfs(int st) {
    if (a.size() == m) {
        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    bool suc = false;
    for (int i = st; i <= n; i++) {
        if (v[i])
            continue;
        a.push_back(i);
        v[i] = 1;
        dfs(i + 1);
        a.pop_back();
        v[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    dfs(1);
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