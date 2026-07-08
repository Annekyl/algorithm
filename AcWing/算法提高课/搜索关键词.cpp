#include "bits/stdc++.h"
// #define int long long
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
const int N = 1e4 + 10;

int tr[N * 50][26], idx = 0;
int cnt[N * 50];
int fail[N * 50];

void insert(string s) {
    int cur = 0;
    for (char c : s) {
        int p = c - 'a';
        if (!tr[cur][p])
            tr[cur][p] = ++idx;
        cur = tr[cur][p];
    }
    cnt[cur]++;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i])
            q.push(tr[0][i]);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (p) {
                fail[p] = tr[fail[t]][i];
                q.push(p);
            } else {
                // 路径压缩，Trie图
                tr[t][i] = tr[fail[t]][i];
            }
        }
    }
}

int quary(string s) {
    int res = 0, p = 0;
    for (char c : s) {
        p = tr[p][c - 'a'];
        int j = p;
        while (j && cnt[j] != -1) {
            res += cnt[j];
            cnt[j] = -1;
            j = fail[j];
        }
    }
    return res;
}

void solve() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    memset(fail, 0, sizeof fail);
    idx = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    build();

    string s;
    cin >> s;
    int ans = quary(s);
    cout << ans << endl;
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
