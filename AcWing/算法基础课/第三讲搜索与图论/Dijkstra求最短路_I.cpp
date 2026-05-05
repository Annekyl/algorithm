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
constexpr int N = 510;

int n, m;
set<pii> g[N];
int d[N];

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x != y) {
            g[x].insert({y, z});
        }
    }

    fill(d + 1, d + n + 1, -1);
    priority_queue<pii> q;
    q.push({0, 1});
    d[1] = 0;
    while (q.size()) {
        int x = q.top().second;
        q.pop();

        for (auto &[y, z] : g[x]) {
            if (d[y] == -1 || d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push({-d[y], y});
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