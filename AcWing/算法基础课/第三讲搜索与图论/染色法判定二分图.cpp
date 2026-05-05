#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;
vi g[N];
int color[N];

bool dfs(int x, int c) {
    color[x] = c;
    for (auto &y : g[x]) {
        if (color[y] == -1) {
            if (!dfs(y, !c)) {
                return false;
            }
        } else if (color[y] == color[x]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    fill(color + 1, color + n + 1, -1);

    bool flag = true;
    FOR(i, 1, n) {
        if (color[i] != -1)
            continue;
        if (!dfs(i, 1)) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}