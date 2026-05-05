#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
int a[N];
int q[N], len = 0;

void solve() {
    memset(q, 0xcf, sizeof q);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) {
        int x = a[i];
        if (x > q[len]) {
            q[++len] = x;
        } else {
            int l = 0, r = len;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (q[mid] >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            q[l] = x;
        }
    }
    cout << len;
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