#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 10;

int cnt[26][N];      // 字符串前j个字符中26个字母出现的次数
vector<int> pos[26]; // 存26个字母出现在字符串中的位置
vector<int> p2[26];  // 字符i所有出现位置的和
vector<int> p3[26];  // 字符i所有出现位置的和 *（2j-1）

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        pos[i].push_back(0);
        p2[i].push_back(0);
        p3[i].push_back(0);
    }

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';

        // 更新cnt前缀数组
        for (int j = 0; j < 26; j++) {
            cnt[j][i + 1] = cnt[j][i];
        }
        cnt[c][i + 1]++;

        // 更新pos数组
        int num = cnt[c][i + 1]; // 字符c已经出现的次数
        int idx = i + 1;         // 字符c在字符串中的第几个位置
        pos[c].push_back(idx);

        p2[c].push_back(p2[c].back() + idx);
        p3[c].push_back(p3[c].back() + idx * (2 * num - 1));
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (x == 1) {
            cout << r - l + 1 << endl;
        } else if (x == 2) {
            int res = 0;
            for (int i = 0; i < 26; i++) {
                int num = cnt[i][r] - cnt[i][l - 1];
                res += num * (num - 1) / 2;
            }
            cout << res << endl;
        } else {
            int res = 0;
            for (int i = 0; i < 26; i++) {
                int first_idx =
                    cnt[i][l - 1] + 1;    // 第一次出现时对应全局第几次出现
                int last_idx = cnt[i][r]; // 最后一次出现时对应全局第几次出现

                // 至少要出现两次
                int num = last_idx - first_idx + 1;
                if (num < 2)
                    continue;

                int offset = first_idx - 1;
                int sum_p2 = p2[i][last_idx] - p2[i][offset];
                int sum_p3 = p3[i][last_idx] - p3[i][offset];

                res +=
                    sum_p3 - (2 * offset + num) * sum_p2 - num * (num - 1) / 2;
            }
            cout << res << endl;
        }
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
