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

int n;

void solve() {
    cin >> n;
    vi a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << -1 << endl;
        return;
    }
    int avg = sum / n;
    vi s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        if (s[i] > avg * i) {
            cout << -1 << endl;
            return;
        }
    }
    vi d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        d[i] = avg * i - s[i];
    }
    vi even, odd;
    even.push_back(0);
    odd.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (i & 1)
            odd.push_back(d[i]);
        else
            even.push_back(d[i]);
    }

    int mx = 0;
    int ans = 0;
    for (int i = 1; i < even.size(); i++) {
        if (even[i] > even[i - 1]) {
            ans += even[i] - even[i - 1];
        }
    }
    // ans += mx;

    mx = 0;
    for (int i = 1; i < odd.size(); i++) {
        if (odd[i] > odd[i - 1]) {
            ans += odd[i] - odd[i - 1];
        }
    }
    // ans += mx;

    cout << ans << endl;
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