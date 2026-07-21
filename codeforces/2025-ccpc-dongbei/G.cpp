#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

void solve() {
    int n, m;
    cin >> n >> m;
    vi cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    vi odd;
    for (int i = 1; i <= n; i++)
        if (cnt[i] % 2)
            odd.push_back(i);

    int k = (odd.size() + 1) / 2;
    cout << k << endl;
    for (int i = 0; i < odd.size(); i++) {
        if (i % 2 == 0)
            cout << odd[i] << ' ';
        else
            cout << odd[i] << endl;
    }
    if (odd.size() % 2)
        cout << odd[odd.size() - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}