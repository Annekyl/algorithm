#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 55;

int n;
int a[N];
int up[N], down[N];
int ans;

void dfs(int idx, int up_cnt, int down_cnt) {
    if (up_cnt + down_cnt >= ans)
        return;
    if (idx == n) {
        ans = min(ans, up_cnt + down_cnt);
        return;
    }

    int k = -1;
    for (int i = 0; i < up_cnt; i++) {
        if (a[idx] > up[i]) {
            if (k == -1 || up[k] < up[i])
                k = i;
        }
    }
    if (k == -1) {
        up[up_cnt] = a[idx];
        dfs(idx + 1, up_cnt + 1, down_cnt);
    } else {
        int temp = up[k];
        up[k] = a[idx];
        dfs(idx + 1, up_cnt, down_cnt);
        up[k] = temp;
    }

    k = -1;
    for (int i = 0; i < down_cnt; i++) {
        if (a[idx] < down[i]) {
            if (k == -1 || down[k] > down[i])
                k = i;
        }
    }
    if (k == -1) {
        down[down_cnt] = a[idx];
        dfs(idx + 1, up_cnt, down_cnt + 1);
    } else {
        int temp = down[k];
        down[k] = a[idx];
        dfs(idx + 1, up_cnt, down_cnt);
        down[k] = temp;
    }
}

void solve() {
    while (cin >> n, n) {
        // cout << n << endl;
        ans = n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        dfs(0, 0, 0);
        cout << ans << endl;
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
