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

bool is_prime[N];
int fa[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

void solve() {
    int a, b, p;
    cin >> a >> b >> p;
	init();
    int ans = b - a + 1;
    for (int i = 2; i <= b; i++) {
        if (!is_prime[i]) {
            if (i >= p) {
                int start = (a + i - 1) / i * i;
                for (int j = start + i; j <= b; j += i) {
                    if (merge(start, j))
                        ans--;
                }
            }
            for (int j = i * 2; j <= b; j += i) {
                is_prime[j] = true;
            }
        }
    }
    cout << ans << endl;
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
