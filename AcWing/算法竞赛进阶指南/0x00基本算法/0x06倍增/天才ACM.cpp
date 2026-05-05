#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 5e5 + 10;

int n, m;
ll t; // t的范围在10^18次方
int a[N];
int b[N]; // 在计算校验值时用作临时数组

ll calc(int st, int ed) {
    int cnt = 0;
    for (int i = st; i <= ed; i++) {
        b[++cnt] = a[i];
    }
    sort(b + 1, b + cnt + 1);

    ll sum = 0; // 校验和
    // 不能出界，也不能超过m对
    for (int i = 1; i <= cnt / 2 && i <= m; i++) {
        sum += ((ll)b[cnt - i + 1] - b[i]) * ((ll)b[cnt - i + 1] - b[i]);
    }
    return sum;
}

void solve() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0; // 分成的段数
    int st = 1;  // 起始位置
    while (st <= n) {
        ans++;

        int ed = st;
        int length = 1; // 初始步长

        while (length > 0) {
            // 分段的结束位置不能超过数组长度
            if (ed + length - 1 > n) {
                length /= 2;
                continue;
            }

            ll sum = calc(st, ed + length - 1);
            if (sum <= t) {
                // 指数增大长度
                ed += length;
                length *= 2;
            } else {
                // 指数缩小倍增的长度
                length /= 2;
            }
        }

        // 更新下一段的起始位置
        st = ed;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}