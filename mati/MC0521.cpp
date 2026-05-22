#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

bool is_prime[200];
int digits[40], len;
int dp[40][40][11][200];
void get_primes() {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < 200; i++) {
        if (is_prime[i])
            for (int j = i + i; j < 200; j += i)
                is_prime[j] = false;
    }
}

int dfs(int pos, int pre, int sum, bool limit) {
    if (pos == len) {
        return is_prime[sum] ? 1 : 0;
    }

    if (!limit && dp[len][pos][pre][sum] != -1)
        return dp[len][pos][pre][sum];

    int up = limit ? digits[pos] : 9;
    int res = 0;

    for (int d = 0; d <= up; d++) {
        if (pre == 10) {
            // 前导零
            if (d == 0) {
                res += dfs(pos + 1, pre, sum, limit && d == up);
            } else {
                res += dfs(pos + 1, d, sum + d, limit && d == up);
            }
        } else {
            if (d == pre)
                continue;
            res += dfs(pos + 1, d, sum + d, limit && d == up);
        }
    }

    if (!limit) {
        dp[len][pos][pre][sum] = res;
    }
    return res;
}

int get_cnt(int x) {
    if (x <= 1)
        return 0;

    len = 0;
    while (x) {
        digits[len++] = x % 10;
        x /= 10;
    }
    reverse(digits, digits + len);

    return dfs(0, 10, 0, true);
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = get_cnt(r) - get_cnt(l - 1);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    get_primes();
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}