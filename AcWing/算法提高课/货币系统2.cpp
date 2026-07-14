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
    vi a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int m = 0, mx = a.back();
    vector<bool> dp(mx + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        if (dp[a[i]])
            continue;
        m++;
        for (int j = a[i]; j <= mx; j++) {
            if (dp[j - a[i]])
                dp[j] = true;
        }
    }
    cout << m << endl;
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