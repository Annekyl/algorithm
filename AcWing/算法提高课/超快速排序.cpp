#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 5e5 + 10;

int n;

int merge(vi &a, vi &temp, int l, int r) {
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    int cnt = 0;
    cnt += merge(a, temp, l, mid);
    cnt += merge(a, temp, mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];

    for (int i = l; i <= r; i++)
        a[i] = temp[i];
    // cout << l << ' ' << r << ' ' << cnt << endl;
    return cnt;
}

void solve() {
    vi a(n), temp(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = merge(a, temp, 0LL, n - 1);
    cout << cnt << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> n, n) {
        solve();
    }

    return 0;
}
