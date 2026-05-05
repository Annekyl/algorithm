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

int n, m;
set<int> g[N];
int d[N];

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        if (x != y) {
            g[x].insert(y);
        }
    }

    fill(d + 1, d + n + 1, -1);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();

        for (auto &y : g[x]) {
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    cout << d[n];
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