#include "bits/stdc++.h"

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
constexpr int N = 1e6 + 10;

int n, m;
char p[N], s[N];
int ne[N], f[N];
vi ans;

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> p[i];
    cin >> m;
    FOR(i, 1, m) cin >> s[i];

    // 求next数组
    ne[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++) {
        while (j > 0 && (j == n || s[i] != p[j + 1]))
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        f[i] = j;
        if (f[i] == n) {
            ans.push_back(i - n);
        }
    }

    for (auto &num : ans) {
        cout << num << " ";
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