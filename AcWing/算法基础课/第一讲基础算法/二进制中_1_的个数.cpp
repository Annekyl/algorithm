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
int a[N];
int cnt[N];

int get(int x) {
    int ans = 0;
    while (x) {
        if (x & 1)
            ans++;
        x >>= 1;
    }
    return ans;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cnt[i] = get(a[i]);
    FOR(i, 1, n) cout << cnt[i] << " ";
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