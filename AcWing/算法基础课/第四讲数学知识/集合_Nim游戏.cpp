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

int n, k;
int a[N];
int rec[N]; // 记忆化数组

int sg(int x) {
    if (rec[x] != -1)
        return rec[x];
    set<int> s;
    FOR(i, 1, k) {
        if (x >= a[i]) {
            s.insert(sg(x - a[i]));
        }
    }
    for (int i = 0;; i++) {
        if (s.find(i) == s.end()) {
            rec[x] = i;
            return i;
        }
    }
}

void solve() {
    cin >> k;
    FOR(i, 1, k) cin >> a[i];
    cin >> n;
    int res = 0;
    memset(rec, -1, sizeof rec);
    while (n--) {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if (res)
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