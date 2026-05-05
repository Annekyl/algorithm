#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 10;

int n;
int g[10][10];
int temp[10][10];
int ans;

int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};

bool check(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5; }

void change(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) {
            temp[nx][ny] ^= 1;
        }
    }
}

bool suc() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (temp[i][j] == 0)
                return false;
        }
    }
    return true;
}

void solve() {
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            g[i][j] = s[j] - '0';
        }
    }

    int ans = INF;
    for (int mask = 0; mask < 32; mask++) {
        memcpy(temp, g, sizeof g);
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if ((mask >> i) & 1) {
                change(0, i);
                cnt++;
            }
        }

        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (temp[i - 1][j] == 0) {
                    change(i, j);
                    cnt++;
                }
            }
        }

        if (cnt <= 6 && suc()) {
            ans = min(ans, cnt);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--)
        solve();

    return 0;
}