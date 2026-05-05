#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int MAX_N = 1e5 + 10;

void solve() {
    int m, h;
    cin >> m >> h;
    int ans = 0;
    for (int i = 1; i <= h; i++) {
        int a, b;
        cin >> a >> b;
        ll sum = 1;
        a %= m;
        while (b) {
            if (b & 1) {
                sum = (sum * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        ans = (ans + sum) % m;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}