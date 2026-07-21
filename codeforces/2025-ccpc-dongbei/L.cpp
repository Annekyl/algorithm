#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vii w(2 * m + 1, vi(n + 1, n)); // 每一个位置的权值
    vector<vector<bool>> st(2 * m + 1,
                            vector<bool>(n + 1, false)); // 每个位置是否被使用
    int q;
    cin >> q;
    vector<pii> ans(q + 1);
    int cnt = 0;

    vi mx(2 * m + 1, n);    // 维护每一排最大的权值
    int remain = 2 * m * n; // 剩余的位置

    auto good = [&](int x, int y) -> bool {
        if (x % 2 == 0) {
            // 偶数行
            return !st[x - 1][y];
        } else {
            return !st[x + 1][y];
        }
    };

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            // 判断是否存在位置
            if (remain == 0) {
                ans[++cnt] = {-1, -1};
            }
            int line = 1; // 选出一个位置，line对应所在行
            for (int i = 1; i <= 2 * m; i++) {
                // 选权值最大的一个位置
                if (mx[line] < mx[i])
                    line = i;
                else if (mx[line] == mx[i]) {
                    // 权值相同时，选好位置或字典序小的位置
                    int last_y = n + 1;
                    bool last_is_good = false;
                    for (int j = 1; j <= n; j++) {
                        if (w[line][j] == mx[line] && good(line, j)) {
                            last_y = j;
                            last_is_good = true;
                            break;
                        } else if (w[line][j] == mx[line]) {
                            last_y = min(last_y, j);
                        }
                    }
                    if (last_is_good)
                        continue;
                    int cur_y = n + 1;
                    bool cur_is_good = false;
                    for (int j = 1; j <= n; j++) {
                        if (w[i][j] == mx[i] && good(i, j)) {
                            cur_y = j;
                            cur_is_good = true;
                            break;
                        } else if (w[i][j] == mx[i]) {
                            cur_y = min(cur_y, j);
                        }
                    }
                    if (cur_is_good)
                        line = i;
                }
            }
            // 分配这个位置给当前编号cnt
            int col = n + 1;
            for (int j = 1; j <= n; j++) {
                if (w[line][j] == mx[line] && good(line, j)) {
                    col = j;
                    break;
                } else if (w[line][j] == mx[line]) {
                    col = min(col, j);
                }
            }
            st[line][col] = true;
            remain--;
            ans[++cnt] = {line, col};

            // 更新影响的一行权值
            mx[line] = -1;
            for (int j = 1; j <= n; j++) {
                if (st[line][col])
                    continue;
                w[line][j] = min(w[line][j], abs(col - j));
                mx[line] = max(mx[line], w[line][j]);
            }
        } else {
            // 释放该位置
            auto [line, col] = ans[x];
            st[line][col] = false;
            remain++;
            // 更新影响的一行权值
            mx[line] = -1;
            for (int j = 1; j <= n; j++) {
                
            }
        }
    }

    for (int i = 1; i <= cnt; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
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