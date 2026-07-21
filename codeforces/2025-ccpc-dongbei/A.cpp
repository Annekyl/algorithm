#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi L(n), R(n);

    // 预处理左边界
    for (int i = 0; i < n; i++) {
        int l = i;
        while (l - 1 >= 0 && a[l - 1] % a[i] == 0 && a[l - 1] > a[i]) {
            l = L[l - 1];
        }
        L[i] = l;
    }
    // 预处理右边界
    for (int i = n - 1; i >= 0; i--) {
        int r = i;
        while (r + 1 < n && a[r + 1] % a[i] == 0) {
            r = R[r + 1];
        }
        R[i] = r;
    }

    // for (int i = 0; i < n; i++)
    //     cout << L[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << R[i] << ' ';
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int len1 = i - L[i] + 1, len2 = R[i] - i + 1;
        // cout << len1 << ' ' << len2 << endl;
        ans += len1 * len2;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}