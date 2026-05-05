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
constexpr int N = 1e6 + 10;

int n, k;
int a[N];
int q[N], hh, tt = -1;

void solve() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    // 滑动窗口中的最小值
    FOR(i, 1, n) {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[i] <= a[q[tt]])
            tt--;
        q[++tt] = i;
        if (i >= k)
            cout << a[q[hh]] << " ";
    }
    cout << endl;

    // 滑动窗口中的最大值
    hh = 0, tt = -1;
    FOR(i, 1, n) {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[i] >= a[q[tt]])
            tt--;
        q[++tt] = i;
        if (i >= k)
            cout << a[q[hh]] << " ";
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