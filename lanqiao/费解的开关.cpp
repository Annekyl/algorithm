#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n;
int state[5][5], press[5][5];

// 获取灯的状态
int getState(int x, int y) {
    int s = state[x][y];
    s ^= press[x][y];   // ⚠️用异或得到每个灯的当前状态
    if (x > 0)
        s ^= press[x - 1][y];
    if (x < 4)
        s ^= press[x + 1][y];
    if (y > 0)
        s ^= press[x][y - 1];
    if (y < 4)
        s ^= press[x][y + 1];
    return s;
}

void solve() {
    int ans = INF;
    // 枚举第一行的全部状态，当第一行的按压状态确定后，可以递推得出所有的按压状态
    for (int mask = 0; mask < 32; mask++) {
        memset(press, 0, sizeof press);
        // 由枚举更新第一行的按压状态
        for (int i = 0; i < 5; i++) {
            press[0][i] = ((mask >> i) & 1);
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                if (getState(i, j) == 0) {
                    press[i + 1][j] = 1;
                } else {
                    press[i + 1][j] = 0;
                }
            }
        }

        bool suc = true;
        for (int i = 0; i < 5; i++) {
            if (getState(4, i) == 0) {
                suc = false;
                break;
            }
        }

        if (!suc) {
            continue;
        } else {
            int cnt = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cnt += press[i][j];
                }
            }
            if (cnt <= 6)   // ⚠️注意判断只有计数值小于等于6时才会更新答案
                ans = min(ans, cnt);
        }
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 5; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++) {
                state[i][j] = s[j] - '0';
            }
        }
        solve();
    }

    return 0;
}