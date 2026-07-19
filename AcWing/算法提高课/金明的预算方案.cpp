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

struct Item {
    int v, w;
};

struct Node {
    Item a;
    vector<Item> b;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> arr(m + 1);
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) {
            arr[i].a = {v, p * v};
        } else {
            arr[q].b.push_back({v, p * v});
        }
    }
    vi dp(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        auto [v1, w1] = arr[i].a;
        int v2 = v1, v3 = v1, v4 = v1, w2 = w1, w3 = w1, w4 = w1;
        if (arr[i].b.size() >= 1) {
            v2 += arr[i].b[0].v;
            w2 += arr[i].b[0].w;
            v4 += arr[i].b[0].v;
            w4 += arr[i].b[0].w;
        }
        if (arr[i].b.size() >= 2) {
            v3 += arr[i].b[1].v;
            w3 += arr[i].b[1].w;
            v4 += arr[i].b[1].v;
            w4 += arr[i].b[1].w;
        }
        for (int j = n; j >= 0; j--) {
            if (j >= v1)
                dp[j] = max(dp[j], dp[j - v1] + w1);
            if (j >= v2)
                dp[j] = max(dp[j], dp[j - v2] + w2);
            if (j >= v3)
                dp[j] = max(dp[j], dp[j - v3] + w3);
            if (j >= v4)
                dp[j] = max(dp[j], dp[j - v4] + w4);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[i]);
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
