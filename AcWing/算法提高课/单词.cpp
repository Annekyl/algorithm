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

int tr[N][26], idx;
int cnt[N];
int pos[210];
int fail[N];
int bfs_order[N], bfs_idx;

void insert(int st, string s) {
    int cur = 0;
    for (char c : s) {
        int p = c - 'a';
        if (!tr[cur][p])
            tr[cur][p] = ++idx;
        cur = tr[cur][p];
        cnt[cur]++;
    }
    pos[st] = cur;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i]) {
            q.push(tr[0][i]);
            bfs_order[++bfs_idx] = tr[0][i];
        }
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        bfs_order[++bfs_idx] = t;

        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (p) {
                fail[p] = tr[fail[t]][i];
                q.push(p);
            } else {
                tr[t][i] = tr[fail[t]][i];
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(i, s);
    }
    build();

    for (int i = bfs_idx; i; i--) {
        int p = bfs_order[i];
        cnt[fail[p]] += cnt[p];
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[pos[i]] << endl;
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
