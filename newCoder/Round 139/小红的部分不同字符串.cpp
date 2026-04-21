#include "bits/stdc++.h"
#define int long long
using namespace std;

const int mod = 998244353;

signed main() {
    int n;
    cin >> n;
    int a[n];
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        in[a[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    // 按照拓扑序列来更新树的贡献
    vector<int> val(n, 1);
    while (q.size()) {
        int x = q.front();
        q.pop();

        int y = a[x];
        val[y] = val[y] * (25 * val[x] % mod) % mod;
        if (--in[y] == 0) {
            q.push(y);
        }
    }

    vector<bool> v(n, false);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (in[i] != 0 && !v[i]) {
            // 找到一个环
            vector<int> cycle;
            int cur = i;
            while (!v[cur]) {
                cycle.push_back(cur);
                v[cur] = true;
                cur = a[cur];
            }

            int dp0 = val[i]; // 第i个节点跟第一个节点颜色相同
            int dp1 = 0;      // 第i个节点跟第一个节点颜色不同
            for (int j = 1; j < cycle.size(); j++) {
                int ndp0 = dp1 * val[cycle[j]] % mod;
                int ndp1 = ((dp0 * 25 % mod) + (dp1 * 24 % mod)) % mod *
                           val[cycle[j]] % mod;

                dp0 = ndp0;
                dp1 = ndp1;
            }

            ans = ans * (dp1 * 26 % mod) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}