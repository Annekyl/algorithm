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
int cnt[N];
int d[N];
int v[N];

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }

    queue<int> q;
    FOR(i, 1, n) q.push(i);
    memset(d, 0, sizeof d);
    memset(cnt, 0, sizeof cnt);
    fill(v + 1, v + n + 1, 1);
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
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No";
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