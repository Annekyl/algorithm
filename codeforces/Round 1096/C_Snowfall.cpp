#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    vi a(n);
    vi ans;
    int cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 6 == 0)
            ans.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 6 != 0 && a[i] % 2 == 0) {
            ans.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 6 != 0 && a[i] % 2 != 0 && a[i] % 3 != 0) {
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 6 != 0 && a[i] % 3 == 0) {
            ans.push_back(a[i]);
        }
    }
    for (int x : ans)
        cout << x << ' ';
    cout << endl;
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
