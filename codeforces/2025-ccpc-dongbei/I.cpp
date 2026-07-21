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
    int n, s, t;
    cin >> n >> s >> t;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (s > t)
        swap(s, t);

    if (s == t) {
        cout << "Yes" << endl;
        return;
    }

    if (n == 1) {
        cout << "No" << endl;
    } else if (n == 2) {
        if (t <= n || s > n) {
            // 同一排
            cout << "No" << endl;
        } else {
            // 不同排
            if (a[s] == t)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    } else {
        if (t <= n || s > n) {
            // 同一排
            cout << "Yes" << endl;
        } else {
            // 不同排
            if (a[s] == t)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
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