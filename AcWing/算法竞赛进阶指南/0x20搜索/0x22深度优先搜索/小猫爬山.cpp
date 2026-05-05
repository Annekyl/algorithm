#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, w;
int a[20];
int ans;

int cab[20];

void dfs(int now, int cnt) {
    if (cnt >= ans)
        return;
    if (now == n + 1) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++) {
        if (cab[i] + a[now] <= w) {
            cab[i] += a[now];
            dfs(now + 1, cnt);
            cab[i] -= a[now]; // 回溯
        }
    }
    cab[cnt + 1] = a[now];
    dfs(now + 1, cnt + 1);
    cab[cnt + 1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ans = n;
    dfs(1, 0);
    cout << ans;

    return 0;
}