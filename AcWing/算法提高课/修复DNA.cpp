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
const int N = 1010;

int n;
int tr[N][4], fail[N], cnt;
bool danger[N];
int dp[N][N];

int get_val(char c) {
    if (c == 'A')
        return 0;
    if (c == 'G')
        return 1;
    if (c == 'C')
        return 2;
    if (c == 'T')
        return 3;
    return -1;
}

void insert(string s) {
    int p = 0;
    for (char c : s) {
        int u = get_val(c);
        if (!tr[p][u])
            tr[p][u] = ++cnt;
        p = tr[p][u];
    }
    danger[p] = true;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 4; i++) {
        if (tr[0][i])
            q.push(tr[0][i]);
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        danger[t] = danger[t] | danger[fail[t]];
        for (int i = 0; i < 4; i++) {
            int &ne = tr[t][i];
            if (ne) {
                fail[ne] = tr[fail[t]][i];
                q.push(ne);
            } else {
                // Trie图优化
                ne = tr[fail[t]][i];
            }
        }
    }
}

int test;
void solve() {
    test++;
    memset(tr, 0, sizeof tr);
    memset(fail, 0, sizeof fail);
    memset(danger, 0, sizeof danger);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    build();
    string s;
    cin >> s;
    int len = s.size();
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= cnt; j++) {
            if (dp[i][j] == INF)
                continue;
            for (int k = 0; k < 4; k++) {
                int ne = tr[j][k];
                if (danger[ne])
                    continue;
                int cost = (get_val(s[i]) == k) ? 0 : 1;
                dp[i + 1][ne] = min(dp[i + 1][ne], dp[i][j] + cost);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j <= cnt; j++) {
        ans = min(ans, dp[len][j]);
    }
    cout << "Case " << test << ": ";
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> n, n) {
        solve();
    }

    return 0;
}
