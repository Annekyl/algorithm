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
constexpr int M = 1e5 + 10;

int n, m, k;
int d[N], backup[N];

struct {
    int x, y, z;
} edge[M];

void solve() {
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        edge[i] = {x, y, z};
    }

    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    FOR(i, 1, k) {
        memcpy(backup, d, sizeof backup);
        FOR(j, 1, m) {
            auto &[x, y, z] = edge[j];
            d[y] = min(d[y], backup[x] + z);
        }
    }
    if (d[n] > INF / 2) {
        cout << "impossible";
    } else {
        cout << d[n];
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