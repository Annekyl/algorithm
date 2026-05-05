#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n;
ll a[MAX_N]; // 原数组
ll d[MAX_N]; // 差分数组

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 计算差分数组
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    // 计算正负数
    ll zheng = 0, fu = 0;
    for (int i = 2; i <= n; i++) {
        if (d[i] > 0)
            zheng += d[i];
        else
            fu -= d[i];
    }

    // 计算答案
    ll ans = max(zheng, fu);
    ll cnt = abs(zheng - fu) + 1;
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}