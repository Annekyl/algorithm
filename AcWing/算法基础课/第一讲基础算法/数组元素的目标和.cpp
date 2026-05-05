#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

void solve() {
    cin >> n >> m >> x;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    // FOR(i, 1, n) cout << a[i] << " ";
    // cout << endl;
    // FOR(i, 1, m) cout << b[i] << " ";
    // cout << endl;

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int i = 1, j = m;
    while (i <= n && j >= 1) {
        int ans = a[i] + b[j];
        // cout << "i:" << i;
        // cout << " j:" << j;
        // cout << " ans:" << ans << endl;
        if (ans == x) {
            cout << i - 1 << " " << j - 1;
            return;
        } else if (ans < x) {
            i++;
        } else {
            j--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}