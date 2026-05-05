#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n, r;
int s[5050][5050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    r = min(r, 5001);

    for (int i = 1; i <= n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] +=
            w; // 转换为1-Based坐标，并且累加价值，防止同一坐标有多个物品
    }

    // 计算二维前缀和
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = r; i <= 5001; i++) {
        for (int j = r; j <= 5001; j++) {
            int sum = s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}