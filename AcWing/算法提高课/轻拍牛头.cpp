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

int a[N];
int cnt[N];
int ans[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i < N; i++) {
        if (cnt[i]) {
            for (int j = i; j < N; j += i) {
                ans[j] += cnt[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[a[i]] - 1 << endl;
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
