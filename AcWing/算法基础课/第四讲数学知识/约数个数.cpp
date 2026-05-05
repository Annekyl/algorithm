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
constexpr int mod = 1e9 + 7;
constexpr int N = 110;

int n;
int a[N];
map<int, int> mp;

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        int ed = sqrt(a[i]);
        int x = a[i];
        FOR(j, 2, ed) {
            while (x % j == 0) {
                mp[j]++;
                x /= j;
            }
        }
        if (x > 1)
            mp[x]++;
    }
    int ans = 1;
    for (auto &[p, c] : mp) {
        // cout << p << "^" << c << endl;
        ans = (ans * (c + 1)) % mod;
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