#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    int a[n + 1], cnt[n + 1] = {0};
    int v[n + 1] = {0};
    bool suc = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]] = 1;
        cnt[a[i]]++;
        if (a[i] > n || cnt[a[i]] > 2) {
            suc = false;
        }
    }

    if (!suc) {
        cout << -1 << endl;
        return;
    }

    vi rem;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            rem.push_back(i);
        }
    }

    int b[n + 1], c[n + 1];
    int pos_b = 0, pos_c = 0;
    int is_fill[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        c[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 2) {
            if (is_fill[a[i]] == 0) {
                b[i] = rem[pos_b++];
                is_fill[a[i]] = 1;
            } else
                c[i] = rem[pos_c++];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
