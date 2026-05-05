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
constexpr int N = 15;

int n;
vb row(N, false), col(N, false), deg(N * 2, false), reg(N * 2, false);
vector<pii> ans;
char g[N][N];

void dfs(int r) {
    if (r == n + 1) {
        FOR(i, 1, n) FOR(j, 1, n) g[i][j] = '.';

        for (auto &[x, y] : ans) {
            g[x][y] = 'Q';
        }

        FOR(i, 1, n) {
            FOR(j, 1, n) cout << g[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }
    FOR(i, 1, n) {
        if (!col[i] && !deg[r - i + n] && !reg[r + i]) {
            col[i] = 1;
            deg[r - i + n] = 1;
            reg[r + i] = 1;
            ans.push_back({r, i});
            dfs(r + 1);
            col[i] = 0;
            deg[r - i + n] = 0;
            reg[r + i] = 0;
            ans.pop_back();
        }
    }
}

void solve() {
    cin >> n;
    dfs(1);
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