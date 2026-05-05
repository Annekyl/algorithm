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
constexpr int N = 1e5 + 10;

int n;
int trie[N][26], sz[N], tot = 1;

void insert(string &s) {
    int p = 1;
    for (auto ch : s) {
        int c = ch - 'a';
        if (trie[p][c] == 0)
            trie[p][c] = ++tot;
        p = trie[p][c];
    }
    sz[p]++;
}

int search(string &s) {
    int p = 1;
    for (auto &ch : s) {
        int c = ch - 'a';
        p = trie[p][c];
        if (p == 0)
            return 0;
    }
    return sz[p];
}

void solve() {
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'I') {
            string x;
            cin >> x;
            insert(x);
        } else {
            string x;
            cin >> x;
            cout << search(x) << endl;
        }
    }
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