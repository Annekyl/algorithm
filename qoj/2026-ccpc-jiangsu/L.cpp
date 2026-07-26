#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vi a(n), d(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    d[1] = a[0];
    for (int i = 1; i < n; i++) {
        d[i + 1] = a[i] - a[i - 1];
    }

    int st = (n % 2 == 0 ? 2 : 1);
    for (int i = st; i <= n; i += 2) {
        if (d[i] % 2 != 0) {
            cout << "Insight" << endl;
            return;
        }
    }
    cout << "Maya" << endl;
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