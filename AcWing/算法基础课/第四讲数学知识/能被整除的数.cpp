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
constexpr int N = 20;

int n, m;
int a[N];

void solve() {
    cin >> n >> m;
    FOR(i, 0, m - 1) cin >> a[i];

    int ans = 0;
    FOR(i, 1, (1 << m) - 1) {
        int cnt = 0; // 质数个数
        int s = 1;   // 质数之和
        FOR(j, 0, m - 1) {
            if (i >> j & 1) {
                cnt++;
                s *= a[j];
                if (s > n) {
                    s = -1;
                    break;
                }
            }
        }
        if (s != -1) {
            if (cnt & 1) {
                ans += n / s;
            } else {
                ans -= n / s;
            }
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