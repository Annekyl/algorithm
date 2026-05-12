#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int q;
    cin >> q;
    int mp[n];
    for (int i = 0; i < n; i++)
        mp[i] = i;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int temp = mp[x];
        mp[x] = mp[y];
        mp[y] = temp;
    }

    for (int i = 0; i < n; i++) {
        int idx = mp[i];
        for (int x : a[idx]) {
            cout << x << " ";
        }
        cout << endl;
    }
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