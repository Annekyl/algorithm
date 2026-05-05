#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int g[10][10]; // 原始矩阵
int a[10][10]; // 临时矩阵
map<int, pii> mp;
int ans = INF;
int ans_mask = 0;

void change(int num) {
    int x = mp[num].first, y = mp[num].second;
    for (int i = 1; i <= 4; i++) {
        a[i][y] ^= 1;
        a[x][i] ^= 1;
    }
    a[x][y] ^= 1;
}

bool check(int st, int &cnt) {
    memcpy(a, g, sizeof a);
    while (st) {
        int low_bit = st & -st;
        change(low_bit);
        st -= low_bit;
        cnt++;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (a[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            char c;
            cin >> c;
            if (c == '+')
                g[i][j] = 1;
            else
                g[i][j] = 0;
            mp[p] = make_pair(i, j);
            p *= 2;
        }
    }

    // for (int i = 1; i <= 4; i++) {
    //     for (int j = 1; j <= 4; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < (1 << 16); i++) {
        // cout << i << endl;
        int cnt = 0; // 记录需要关几次门
        if (check(i, cnt)) {
            // cout << cnt << endl;
            if (cnt < ans) {
                ans = cnt;
                ans_mask = i;
            }
        }
    }
    cout << ans << endl;
    while (ans_mask) {
        int low_bit = ans_mask & (-ans_mask);
        cout << mp[low_bit].first << " " << mp[low_bit].second << endl;
        ans_mask -= low_bit;
    }
    return 0;
}