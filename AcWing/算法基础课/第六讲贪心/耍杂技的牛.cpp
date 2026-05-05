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
constexpr int N = 5e4 + 10;

/*
ans的初始化，需要注意不能初始化为0，因为答案可能为负数
*/

int n;
pii a[N];
int s[N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, [](const pii &a, const pii &b) {
        return a.first + a.second < b.first + b.second;
    });

    // 预处理前缀和
    FOR(i, 1, n) s[i] = s[i - 1] + a[i].first;

    int ans = -INF;
    FOR(i, 1, n) { ans = max(ans, s[i - 1] - a[i].second); }
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