#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 3e5 + 10;

int n, m;
int a[N];
int s[N];
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int ans = INT_MIN; // 要用最小值
    int l = 1, r = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        // 保证窗口大小不超过m
        while (l <= r && q[l] < i - m) {
            l++;
        }
        // 更新答案
        ans = max(ans, s[i] - s[q[l]]);
        // 保证前缀和单调递增
        while (l <= r && s[q[r]] >= s[i])
            r--;
        q[++r] = i;
    }
    cout << ans;
    return 0;
}