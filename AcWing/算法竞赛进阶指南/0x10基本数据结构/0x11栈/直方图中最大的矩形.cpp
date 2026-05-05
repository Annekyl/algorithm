#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;
ll h[N];  // 高度
int w[N]; // 高度
ll s[N];  // 栈
int tt;   // 栈顶指针
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        h[n + 1] = 0;
        tt = 0;
        ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (h[i] > s[tt]) {
                // 当前高度高于栈顶，直接入栈
                   s[++tt] = h[i];
                w[tt] = 1;
            } else {
                // 否则弹出全部高度大于当前元素的栈顶元素
                int width = 0;
                while (s[tt] > h[i]) {
                    width += w[tt];
                    ans = max(ans, s[tt] * width);
                    tt--;
                }
                s[++tt] = h[i];
                w[tt] = width + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}