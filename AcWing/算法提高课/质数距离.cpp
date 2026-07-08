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
const int N = 1e6 + 10;

bool st[N];
int prime[N], cnt;
int l, r;

void init(int n) {
    cnt = 0;
    memset(st, 0, sizeof st);

    for (int i = 2; i < n; i++) {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] * i < n; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    init(50000);

    memset(st, 0, sizeof st);
    for (int i = 0; i < cnt; i++) {
        int p = prime[i];
        for (int j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p) {
            st[j - l] = true;
        }
    }
    cnt = 0;
    for (int i = 0; i <= r - l; i++) {
        if (!st[i] && i + l >= 2) {
            prime[cnt++] = i + l;
        }
    }
    if (cnt < 2) {
        cout << "There are no adjacent primes." << endl;
    } else {
        int mn = 0, mx = 0;
        for (int i = 0; i < cnt - 1; i++) {
            int d = prime[i + 1] - prime[i];
            if (d > prime[mx + 1] - prime[mx])
                mx = i;
            if (d < prime[mn + 1] - prime[mn])
                mn = i;
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", prime[mn],
               prime[mn + 1], prime[mx], prime[mx + 1]);
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> l >> r) {
        solve();
    }

    return 0;
}
