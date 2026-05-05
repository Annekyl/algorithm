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
constexpr int N = 15;

int n, m;
int f[N][1 << N];
bool st[1 << N];

void solve() {
    // cin >> n >> m;

    // 预处理合法状态
    FOR(i, 0, (1 << n) - 1) {
        int cnt = 0; // 统计连续的空格
        st[i] = true;
        // 遍历该状态的每一位
        FOR(j, 0, n - 1) {
            if ((i >> j) & 1) {
                if (cnt & 1)
                    st[i] = false;
                cnt = 0;
            } else {
                cnt++;
            }
        }

        if (cnt & 1)
            st[i] = false;
    }

    // 状态转移
    memset(f, 0, sizeof f);
    f[0][0] = 1;

    // 遍历每一列
    FOR(i, 1, m) {
        // 遍历每一个状态
        FOR(j, 0, (1 << n) - 1) {
            // 遍历该状态的前一列的状态
            FOR(k, 0, (1 << n) - 1) {
                if ((j & k) == 0 && st[j | k] == true) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }

    cout << f[m][0] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (cin >> n >> m, n && m) {
        solve();
    }
    return 0;
}