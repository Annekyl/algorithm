#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;
vi a(2 * N);

int get_mex(int l, int r) {
    vector<bool> st(n, false);
    for (int i = l; i <= r; i++) {
        st[a[i]] = true;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (!st[i]) {
            ans = i;
            break;
        }
    }
    return ans;
}

int calc(int mid, bool flag) {
    int l = mid, r = mid;
    if (flag)
        r++;
    if (l < r && a[l] != a[r]) { // ⚠️两个0时可能l和r不相等
        return 0;
    }
    while (l - 1 >= 0 && r + 1 < n * 2 && a[l - 1] == a[r + 1]) {
        l--;
        r++;
    }

    return get_mex(l, r);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n * 2; i++)
        cin >> a[i];
    int left = -1, right;
    for (int i = 0; i < n * 2; i++) {
        if (a[i] == 0) {
            if (left == -1)
                left = i;
            else
                right = i;
        }
    }

    int ans = 0;
    ans = max(ans, calc(left, false));
    ans = max(ans, calc(right, false));
    ans = max(ans, calc(left + right >> 1, true));  // ⚠️两个0时区间长度可奇可偶
    ans = max(ans, calc(left + right >> 1, false));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
