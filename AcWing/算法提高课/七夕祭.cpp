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

int calc(vi &a, int n, int cnt) {
    int s[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i] - cnt;
    }
    sort(s + 1, s + n + 1);
    int mid = s[(n + 1) / 2];
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += abs(mid - s[i]);
    }
    return res;
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vi rows(n + 1, 0), cols(m + 1, 0);
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        rows[x]++;
        cols[y]++;
    }

    int rcnt, ccnt;
    if (t % n == 0 && t % m == 0) {
        cout << "both ";
        rcnt = calc(rows, n, t / n);
        ccnt = calc(cols, m, t / m);
        cout << rcnt + ccnt << endl;
    } else if (t % n == 0) {
        cout << "row ";
        rcnt = calc(rows, n, t / n);
        cout << rcnt << endl;
    } else if (t % m == 0) {
        cout << "column ";
        ccnt = calc(cols, m, t / m);
        cout << ccnt << endl;
    } else {
        cout << "impossible" << endl;
    }
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
