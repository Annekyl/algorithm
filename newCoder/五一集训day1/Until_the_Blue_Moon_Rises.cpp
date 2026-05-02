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
vi a;

bool is_prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve() {
    cout << endl;
    cin >> n;
    a.resize(n);
    for (int &x : a)
        cin >> x;

    int sum = 0;
    for (int x : a)
        sum += x;

    if (n == 1) {
        cout << (is_prime(sum) ? "Yes" : "No") << endl;
        return;
    }
    if (n == 2) {
        if ((sum & 1) == 0) {
            cout << (sum >= 4 ? "Yes" : "No") << endl;
        } else {
            cout << (is_prime(sum - 2) ? "Yes" : "No") << endl;
        }
        return;
    }
    if (sum < n * 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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
