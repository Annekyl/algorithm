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
const int N = 1e5 + 10;

int n;
int tr[N];

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int quary(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
        add(i, 1);

    int ans[n + 1];
    for (int i = n; i; i--) {
        int target = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (quary(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[i] = l;
        add(l, -1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
