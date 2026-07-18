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

struct Stone {
    int s, e, l;
    bool operator<(const Stone &other) const {
        return s * other.l < other.s * l;
    }
};

int test;

void solve() {
    int n;
    cin >> n;
    vector<Stone> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].e >> a[i].l;
        sum += a[i].s;
    }
    sort(a.begin(), a.end());
    vi dp(sum + 1, 0);
    for (int i = 0; i < n; i++) {
        auto [s, e, l] = a[i];
        for (int j = sum; j >= s; j--) {
            int add = max(0LL, e - l * (j - s));
            dp[j] = max(dp[j], dp[j - s] + add);
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; i++)
        ans = max(ans, dp[i]);
    test++;
    cout << "Case #" << test << ": " << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
