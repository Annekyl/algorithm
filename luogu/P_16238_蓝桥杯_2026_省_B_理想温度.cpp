#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], d[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - b[i];

    int z = 0; // 一共的零的数量
    for (int i = 1; i <= n; i++)
        z += (d[i] == 0);

    // 前缀零的数量
    vector<int> pz(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pz[i] = pz[i - 1] + (d[i] == 0);
    }

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0)
            continue;
        mp[d[i]].push_back(i);
    }

    int ans = z;
    for (auto [num, arr] : mp) {
        int g = 0 - 1 - pz[arr[0] - 1];
        int f;
        for (int i = 0; i < arr.size(); i++) {
            f = i - pz[arr[i]];
            ans = max(ans, f - g + z);
            g = min(g, i - 1 - pz[arr[i] - 1]); // ⚠️维护g的最小值
        }
        // ans = max(ans, f - g + z);
    }

    cout << ans << endl;
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
