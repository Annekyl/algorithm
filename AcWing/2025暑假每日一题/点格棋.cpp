#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 110;

int n, m, s;
int idx, stx, sty, edx, edy;
vector<int> ans;

bool line[N][N];
bool row[N][N];

bool valid(pii p1, pii p2) {
    if (p1.first < 1 || p1.first > n || p1.second < 1 || p1.second > m ||
        p2.first < 1 || p2.first > n || p2.second < 1 || p2.second > m)
        return false;
    int dx = abs(p1.first - p2.first);
    int dy = abs(p1.second - p2.second);
    return dx == 1 && dy == 0 || dx == 0 && dy == 1;
}

int check(int stx, int sty, int st) {
    int cnt = 0;
    if (st == 0) {
        // 垂直线
        if (sty - 1 > 0 && stx + 1 <= n && row[stx][sty - 1] &&
            line[stx][sty - 1] && line[stx + 1][sty - 1]) {
            cnt++;
        }
        if (sty + 1 <= m && stx + 1 <= n && row[stx][sty + 1] &&
            line[stx][sty] && line[stx + 1][sty]) {
            cnt++;
        }
    } else {
        // 水平线
        if (line[stx - 1][sty] && row[stx - 1][sty] && row[stx - 1][sty + 1]) {
            cnt++;
        }
        if (line[stx + 1][sty] && row[stx][sty] && row[stx][sty + 1]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    int now = 0; // 当前下棋的人
    int sc[2] = {0, 0};
    memset(line, 0, sizeof line);
    memset(row, 0, sizeof row);
    for (int i = 1; i <= s; i++) {
        cin >> idx >> stx >> sty >> edx >> edy;
        if (idx != now) {
            ans.push_back(i);
            continue;
        }

        // 连线是否合法
        if (!valid({stx, sty}, {edx, edy})) {
            ans.push_back(i);
            continue;
        }

        if (stx > edx || sty > edy) {
            swap(stx, edx);
            swap(sty, edy);
        }

        if (edx - stx == 1) { // 垂直线
            if (row[stx][sty]) {
                ans.push_back(i);
                continue;
            }
            row[stx][sty] = 1;
            int cnt = check(stx, sty, 0);
            if (cnt) {
                sc[idx] += cnt;
                continue;
            }
        } else if (edy - sty == 1) { // 水平线
            if (line[stx][sty]) {
                ans.push_back(i);
                continue;
            }
            line[stx][sty] = 1;
            int cnt = check(stx, sty, 1);
            if (cnt) {
                sc[idx] += cnt;
                continue;
            }
        }
        now ^= 1;
    }
    // cout << sc[0] << " " << sc[1] << endl;

    if (ans.size()) {
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    if (sc[0] > sc[1]) {
        cout << 0 << " " << sc[0];
    } else {
        cout << 1 << " " << sc[1];
    }
    return 0;
}