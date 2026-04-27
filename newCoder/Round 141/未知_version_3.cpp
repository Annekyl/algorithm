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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    int mx_cnt = (m + 1) * m / 2 + 1;
    int mn_cnt = m * 2;
    if (n < mn_cnt || n > mx_cnt) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int idx = 0;
    int v[n + 1];
    v[1] = ++idx;
    // 先输出主链
    for (int i = 2; i <= m + 1; i++) {
        v[i] = ++idx;
        cout << v[i - 1] << ' ' << v[i] << endl;
    }

    // 其他链的分支长度
    vector<int> len(m + 1, 1);
    int remain = n - mn_cnt; // 剩余需要分配的节点个数
    for (int i = 1; i < m; i++) {
        int add = min(remain, i - 1);
        len[i] += add;
        remain -= add;
        if (remain == 0)
            break;
    }

    for (int i = 1; i < m; i++) {
        int x = v[i - len[i] + 1];
        for (int j = 0; j < len[i]; j++) {
            int y = ++idx;
            cout << x << " " << y << endl;
            x = y;
        }
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
