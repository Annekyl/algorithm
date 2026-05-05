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

int n, x;

void solve() {
    cin >> n >> x;
    if (x == 1) {
        if ((n & (n - 1)) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }
    int s = 0;
    int temp = n;
    while (temp) {
        s += (temp % x);
        temp /= x;
    }
    for (int i = 0; i <= 31; i++) {
        int k = 1 << i;
        if (k >= s && k <= n) {
            if (n % (x - 1) == k % (x - 1)) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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
