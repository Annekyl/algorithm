#include "bits/stdc++.h"

#define int unsigned long long
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
const int P = 131;

int n, m;
char s[N];
int p[N], h[N];

int get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> s[i];

    // 预处理前缀和
    p[0] = 1;
    FOR(i, 1, n) {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }

    while (m--) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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