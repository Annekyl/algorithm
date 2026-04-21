#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void dfs(int x, vector<int> &path) {
    if (x == n + 1) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    path.push_back(x);
    dfs(x + 1, path);
    path.pop_back();
    dfs(x + 1, path);
}

void solve() {
    cin >> n;
    vector<int> path;
    dfs(1, path);
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