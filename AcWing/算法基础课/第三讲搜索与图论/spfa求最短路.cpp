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
vector<pii> g[N];
int d[N];
bool v[N];

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }

    memset(d, 0x3f, sizeof d);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    v[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (auto &[y, z] : g[x]) {
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
    if (d[n] == INF)
        cout << "impossible";
    else
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