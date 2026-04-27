#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 110;

int n;
int path[N];

bool dfs(int u, int depth) {
    // cout << u << endl;
    if (u > depth)
        return false;
    if (path[u - 1] == n)
        return true;

    bool st[N];
    memset(st, 0, sizeof st);
    for (int i = u - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int sum = path[i] + path[j];
            if (sum > n || sum < path[u - 1] || st[sum])
                continue;
            path[u] = sum;
            st[sum] = true;
            if (dfs(u + 1, depth))
                return true;
        }
    }
    return false;
}

void solve() {
    path[0] = 1;
    int depth = 1;
    while (!dfs(1, depth)) {
        depth++;
    }
    for (int i = 0; i < depth; i++) {
        cout << path[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> n, n) {
        solve();
    }

    return 0;
}
