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

int n;
int st, ed;
pii a[N];

void solve() {
    cin >> st >> ed;
    cin >> n;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    int ans = 0;
    FOR(i, 1, n) {
        int j = i;
        int r = -INF;

        while (j <= n && a[j].first <= st) {
            r = max(r, a[j].second);
            j++;
        }

        // 无法覆盖当前的左区间
        if (r < st) {
            cout << -1;
            return;
        }

        ans++;

        // 已经覆盖全部区间
        if (r >= ed) {
            cout << ans;
            return;
        }

        st = r;
        i = j - 1;
    }

    // 全部区间遍历完后仍然没有覆盖右区间
    cout << -1 << endl;
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