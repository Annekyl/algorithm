#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 5010;

int fa[N];

void init() {
    for (int i = 0; i < N; i++)
        fa[i] = i;
}

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    init();
    while (m--) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    while (p--) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
