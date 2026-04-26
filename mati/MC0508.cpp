#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e6 + 10;

int n, q;
vector<int> cnt(N, 0);

void solve() {
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        vi used;
        for (int i = l; i <= r; i++) {
            used.push_back(a[i]);
            cnt[a[i]]++;
            ans = max(ans, cnt[a[i]]);
        }
        cout << ans << endl;
        for (int idx : used) {
            cnt[idx] = 0;
        }
    }
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