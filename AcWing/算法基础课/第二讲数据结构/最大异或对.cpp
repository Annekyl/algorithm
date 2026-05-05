#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 4e6 + 10;

int n;

int trie[N][2], tot = 1;
bool ed[N];

void insert(int x) {
    int p = 1;
    REF(i, 31, 0) {
        int bit = (x >> i) & 1;
        if (trie[p][bit] == 0)
            trie[p][bit] = ++tot;
        p = trie[p][bit];
    }
    ed[p] = 1;
}

int find(int x) {
    int p = 1, ans = 0;
    REF(i, 31, 0) {
        int bit = (x >> i) & 1;
        if (trie[p][bit ^ 1] != 0) {
            p = trie[p][bit ^ 1];
            ans ^= (1 << i);
        } else if (trie[p][bit] != 0) {
            p = trie[p][bit];
        } else {
            break;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    int ans = 0;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        ans = max(ans, find(x));
        insert(x);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}