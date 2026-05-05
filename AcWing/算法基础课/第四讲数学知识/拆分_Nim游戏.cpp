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
constexpr int N = 110;

int n;
int a[N];
int rec[N];

int sg(int x) {
    if (rec[x] != -1)
        return rec[x];

    set<int> s;
    FOR(i, 0, x - 1) {
        FOR(j, 0, i) { s.insert(sg(i) ^ sg(j)); }
    }

    for (int i = 0;; i++) {
        if (s.find(i) == s.end()) {
            rec[x] = i;
            return i;
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int ans = 0;
    memset(rec, -1, sizeof rec);
    FOR(i, 1, n) { ans ^= sg(a[i]); }
    if (ans)
        cout << "Yes";
    else
        cout << "No";
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