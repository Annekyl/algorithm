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

    int q;
    cin >> q;
    vector<pii> ans(q + 1);
    int cnt = 0;

    vector<vector<bool>> st(2 * m + 1,
                            vector<bool>(n + 1, false)); // 每个位置是否被使用
    vi w(2 * m + 1, n);                                  // 维护每一排最大的权值
    vi mx_good(2 * m + 1, -1);
    vi mx_any(2 * m + 1, -1);
    vi empty(2 * m + 1, n);
    int remain = 2 * m * n; // 剩余的位置

    auto good = [&](int x, int y) -> bool {
        if (x % 2 == 0) {
            // 偶数行
            return !st[x - 1][y];
        } else {
            return !st[x + 1][y];
        }
    };

    auto opp = [&](int x) -> int { return (x & 1) ? x + 1 : x - 1; };

    auto update = [&](int line) {
        if (empty[line] == 0) {
            w[line] = -1;
            mx_good[line] = -1;
            mx_any[line] = -1;
        } else if (empty[line] == n) {
            w[line] = n;
            mx_any[line] = 1;
            mx_good[line] = -1;
            for (int j = 1; j <= n; j++) {
                // 当前位置有人则跳过
                if (!st[line][j] && good(line, j)) {
                    mx_good[line] = j;
                    break;
                }
            }
        } else {
            // 更新当前最大权值等信息
            vi L(n + 1, INF), R(n + 1, INF), line_w(n + 1, n);
            int cur = -1;
            for (int j = 1; j <= n; j++) {
                if (st[line][j]) {
                    cur = j;
                } else {
                    if (cur != -1)
                        L[j] = j - cur;
                }
            }
            cur = -1;
            for (int j = n; j > 0; j--) {
                if (st[line][j]) {
                    cur = j;
                } else {
                    if (cur != -1)
                        R[j] = cur - j;
                }
            }
            w[line] = -1;
            mx_any[line] = -1;
            mx_good[line] = -1;
            for (int j = 1; j <= n; j++) {
                if (st[line][j])
                    continue;
                line_w[j] = min(L[j], R[j]);
                w[line] = max(w[line], line_w[j]);
            }
            for (int j = 1; j <= n; j++) {
                if (st[line][j])
                    continue;
                if (line_w[j] == w[line] && mx_any[line] == -1)
                    mx_any[line] = j;
                if (line_w[j] == w[line] && mx_good[line] == -1 &&
                    good(line, j))
                    mx_good[line] = j;
            }
        }
    };

    for (int i = 1; i <= 2 * m; i++)
        update(i);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cnt = x;
            if (remain == 0) {
                ans[x] = {-1, -1};
            } else {
                int select = -1;
                for (int i = 1; i <= 2 * m; i++) {
                    if (select == -1 || w[select] < w[i]) {
                        select = i;
                    } else if (w[select] == w[i]) {
                        if (mx_good[select] == -1 && mx_good[i] != -1) {
                            select = i;
                        }
                    }
                }
                // 分配座位
                int col =
                    (mx_good[select] == -1 ? mx_any[select] : mx_good[select]);
                st[select][col] = true;
                empty[select]--;
                remain--;
                ans[x] = {select, col};
                update(select);
                update(opp(select));
            }
        } else {
            auto [line, col] = ans[x];
            if (line == -1)
                continue;
            remain++;
            st[line][col] = false;
            empty[line]++;
            update(line);
            update(opp(line));
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