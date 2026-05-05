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

double n;

void solve() {
    cin >> n;
    double l = -10000, r = 10000, eps = 1e-8;
    while (r - l >= eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.6f", l);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}