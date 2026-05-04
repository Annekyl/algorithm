#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    FOR(i, 1, n) { cin >> a[i]; }
    sort(a.begin() + 1, a.end());

    // FOR(i, 1, n) cout << a[i] << ' ';
    // cout << endl;

    int ans = 0;
    int st = -1;
    int i = 1, j = 2;
    FOR(k, 3, n) {
        if (a[i] + a[j] > a[k]) {
            if (k - i + 1 > ans) {
                ans = k - i + 1;
                st = i;
            }
        } else {
            while (a[i] + a[j] <= a[k]) {
                i = j;
                j++;
            }
        }
    }
    if (ans < 3) {
        cout << 0 << endl;
    } else {
        cout << ans << " ";
        FOR(i, st, st + ans - 1) { cout << a[i] << ' '; }
        cout << endl;
    }
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