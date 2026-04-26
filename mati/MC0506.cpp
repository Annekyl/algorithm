#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 10007;
constexpr int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int left[n + 1], right[n + 1];
    for (int i = 1; i <= n; i++) {
        left[i] = 0;
        right[i] = 0;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i])
                left[i]++;
        }
        for (int j = n; j > i; j--) {
            if (a[j] < a[i])
                right[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) {
                // cout << i << " " << j << endl;
                ans = (ans + left[i] * right[j] % mod) % mod;
            }
        }
    }
    cout << ans << endl;
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