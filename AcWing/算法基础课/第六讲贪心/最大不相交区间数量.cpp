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
pii a[N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    int ans = 1;
    int idx = a[1].second;
    FOR(i, 2, n) {
        if (idx < a[i].first) {
            ans++;
            idx = a[i].second;
        } else if (a[i].first <= idx && idx <= a[i].second) {
            continue;
        } else {
            idx = a[i].second;
        }
    }
    cout << ans;
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