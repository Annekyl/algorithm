#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
vector<int> a;
bool v[N];

void dfs() {
    if (a.size() == n) {
        for (auto num : a) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i])
            continue;
        a.push_back(i);
        v[i] = 1;
        dfs();
        a.pop_back();
        v[i] = 0;
    }
}

void solve() {
    cin >> n;
    dfs();
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