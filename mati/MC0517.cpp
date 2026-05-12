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

int n, m;

void solve() {
    cin >> n >> m;
    pii a[n];
    int cnt[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    while (m--) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int i = 0; i < n; i++ ) {
            auto [x1, y1] = a[i];
            int d = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            if (d <= r * r) {
                cnt[i] ++ ;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[i] << endl;
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