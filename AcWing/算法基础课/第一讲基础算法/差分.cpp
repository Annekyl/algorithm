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

int n, m;
int a[N];
int d[N];

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    FOR(i, 1, m) {
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r + 1] -= c;
    }
    FOR(i, 1, n) {
        d[i] += d[i - 1];
        cout << d[i] << " ";
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