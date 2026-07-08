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
const int N = 2e5 + 10;

int n;
int a[N];
int st[N][18];

void init() {
    for (int j = 0; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if (!j)
                st[i][j] = a[i];
            else
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int quary(int l, int r) {
    int len = r - l + 1;
    int k = log(len) / log(2);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int ans = quary(a, b);
        cout << ans << endl;
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
