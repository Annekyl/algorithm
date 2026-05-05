#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n;
int d[15]; // 三塔汉诺塔的最小移动次数
int f[15]; // 四塔汉诺塔的最小移动次数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin >> n;
    memset(d, 0x3f, sizeof d);
    memset(f, 0x3f, sizeof f);

    d[1] = 1;
    for (int i = 2; i <= 12; i++) {
        d[i] = 2 * d[i - 1] + 1;
    }

    f[1] = 1;
    for (int i = 2; i <= 12; i++) {
        for (int j = 1; j < i; j++) {
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
        }
    }

    for (int i = 1; i <= 12; i++)
        cout << f[i] << endl;
    return 0;
}