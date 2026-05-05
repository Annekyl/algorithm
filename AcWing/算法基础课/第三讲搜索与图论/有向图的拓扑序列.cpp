#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

/*
重边可以用set过滤掉，但是自环不能去掉，有自环的话是不存在拓扑序的
*/

int n, m;
set<int> g[N];
int deg[N]; // 入度
vi ans;

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        if (g[x].find(y) == g[x].end()) {
            g[x].insert(y);
            deg[y]++;
        }
    }

    // FOR(i, 1, n) cout << deg[i] << " ";
    // cout << endl;
    queue<int> q;
    FOR(i, 1, n) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (auto &y : g[x]) {
            if (--deg[y] == 0) {
                q.push(y);
            }
        }
    }

    if (ans.size() != n)
        cout << -1;
    else {
        for (auto &num : ans) {
            cout << num << " ";
        }
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